#include "Renderer.h"

Renderer::Renderer(const int samples, const int max_depth) {
    set_samples(samples);
    set_max_depth(max_depth);
}

void Renderer::render(const shared_ptr<SphereList> &spheres, const shared_ptr<Camera> &camera,
                      const shared_ptr<RenderTarget> &render_target) const {
    // Ensure spheres is not nullptr
    if (spheres == nullptr)
        throw RendererException("Renderer::render(): spheres cannot be nullptr");

    // Ensure camera is not nullptr
    if (camera == nullptr)
        throw RendererException("Renderer::render(): camera cannot be nullptr");

    // Ensure render_target is not nullptr
    if (render_target == nullptr)
        throw RendererException("Renderer::render(): render_target cannot be nullptr");

    // Get RT_CAMERA_VALUES for ray query information
    auto rt_camera_values = initializeRTCamera(camera, render_target);

    // Rendered rows
    int rendered_rows = 0;

    for (int j = 0; j < render_target->get_height(); j++) {
        for (int i = 0; i < render_target->get_width(); i++) {
            vec3 color{0};

            for (int k = 0; k < get_samples(); k++) {
                Ray ray = getRayAtPixel(i, j, rt_camera_values);
                color += getRayColor(ray, spheres).get_color();
            }

            color /= get_samples();
            render_target->set_pixel(i, j, Color(color));
        }

        rendered_rows += 1;
        std::cout << "Rendering in progress: " << 100.0f * static_cast<float>(rendered_rows) / static_cast<float>(
            render_target->get_height()) << "%\n";
    }
}

RT_CAMERA_VALUES Renderer::initializeRTCamera(const shared_ptr<Camera> &camera,
                                              const shared_ptr<RenderTarget> &render_target) {
    // Ensure camera is not nullptr
    if (camera == nullptr)
        throw RendererException("Renderer::initializeRTCamera(): camera cannot be nullptr");

    // Ensure render_target is not nullptr
    if (render_target == nullptr)
        throw RendererException("Renderer::initializeRTCamera(): render_target cannot be nullptr");

    // Continue, all values validated and guaranteed to not cause issues
    RT_CAMERA_VALUES rtc{};

    rtc.position = camera->get_position();
    rtc.direction = camera->get_look_at();
    rtc.up_direction = camera->get_up_direction();

    rtc.focal_length = length(rtc.position - rtc.direction);
    rtc.theta = degrees_to_radians(camera->get_fov());
    rtc.h = std::tan(rtc.theta / 2.0f);
    rtc.viewport_height = 2.0f * rtc.h * rtc.focal_length;
    rtc.viewport_width = rtc.viewport_height * (
                             static_cast<float>(render_target->get_width()) / static_cast<float>(render_target->
                                 get_height()));

    rtc.w = normalize(rtc.position - rtc.direction);
    rtc.u = normalize(cross(rtc.up_direction, rtc.w));
    rtc.v = cross(rtc.w, rtc.u);

    rtc.viewport_u = rtc.viewport_width * rtc.u;
    rtc.viewport_v = rtc.viewport_height * -rtc.v;

    rtc.pixel_delta_u = rtc.viewport_u / static_cast<float>(render_target->get_width());
    rtc.pixel_delta_v = rtc.viewport_v / static_cast<float>(render_target->get_height());

    rtc.viewport_upper_left = camera->get_position() - (rtc.focal_length * rtc.w) - rtc.viewport_u / 2.0f - rtc
                              .viewport_v / 2.0f;
    rtc.pixel_upper_left = rtc.viewport_upper_left + 0.5f * (rtc.pixel_delta_u + rtc.pixel_delta_v);

    return rtc;
}

Ray Renderer::getRayAtPixel(const int i, const int j, const RT_CAMERA_VALUES &rt_camera_values) {
    // Ensure i is non-negative
    if (i < 0)
        throw RendererException("Renderer::getRayAtPixel(): i must be positive");

    // Ensure j is non-negative
    if (j < 0)
        throw RendererException("Renderer::getRayAtPixel(): j must be positive");

    // Per pixel sample offset for antialiasing
    const auto offset = sampleSquare();

    const auto pixel_sample = rt_camera_values.pixel_upper_left
                              + (static_cast<float>(i) + offset.x) * rt_camera_values.pixel_delta_u
                              + (static_cast<float>(j) + offset.y) * rt_camera_values.pixel_delta_v;

    // Get ray through pixel by random offset for antialiasing
    const auto ray_origin = rt_camera_values.position;
    const auto ray_direction = pixel_sample - ray_origin;

    // Return ray
    return {ray_origin, ray_direction};
}

Color Renderer::getRayColor(Ray ray, const shared_ptr<SphereList> &spheres) const {
    // Ensure spheres is not nullptr
    if (spheres == nullptr)
        throw RendererException("Renderer::getRayColor(): spheres cannot be nullptr");

    // Calculate ray color
    int depth = this->get_max_depth();

    HitRecord record{};
    vec3 color{0};
    vec3 attenuation{1.0f};

    while (depth > 0) {
        if (spheres->Hit(ray, 0.001, 1000000, record)) {
            scatter(record, ray);
            attenuation *= record.get_color().get_color();
            depth--;
        } else {
            color += attenuation * getSkyColor(ray).get_color();
            depth = 0;
        }
    }

    return Color(color);
}

Color Renderer::getSkyColor(const Ray &ray) {
    const vec3 unit_direction = normalize(ray.get_direction());
    auto a = 0.5f * (unit_direction.z + 1);
    const auto bottom_color = vec3(0);
    const auto top_color = vec3(1);
    return Color(((1.0f - a) * bottom_color) + (a * top_color));
}

bool Renderer::scatter(const HitRecord &hit_record, Ray &scattered_ray) {
    vec3 direction = hit_record.get_normal() + random_unit_vector();

    if (is_near_zero(direction))
        direction = hit_record.get_normal();

    scattered_ray = Ray(hit_record.get_point(), direction);
    return true;
}

void Renderer::set_samples(const int samples) {
    // Ensure samples is greater than zero
    if (samples <= 0)
        throw RendererException("Renderer::set_samples(): samples must be positive");

    // Set samples
    this->samples = samples;
}

void Renderer::set_max_depth(const int max_depth) {
    // Ensure max_depth is greater than zero
    if (max_depth <= 0)
        throw RendererException("Renderer::set_max_depth(): max_depth must be positive");

    // Set max_depth
    this->max_depth = max_depth;
}
