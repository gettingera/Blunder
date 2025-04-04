#ifndef RAYTRACER_H
#define RAYTRACER_H
#include <Utils/Headers.h>
#include <Geometry/SphereList.h>
#include <Renderer/RenderTarget.h>
#include <Camera/Camera.h>

/**
 * Utility structure to hold necessary camera values and computations for ray tracing.
 *
 * Values are largely undocumented for now. They will be documented soon. UNFINISHED.
 */
struct RT_CAMERA_VALUES {
    float focal_length;
    float theta;
    float h;
    float viewport_height;
    float viewport_width;

    vec3 position;
    vec3 direction;
    vec3 up_direction;
    vec3 u;
    vec3 v;
    vec3 w;
    vec3 viewport_u;
    vec3 viewport_v;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    vec3 viewport_upper_left;
    vec3 pixel_upper_left;
};


/**
 * Raytracer renderer.
 * Useful for rendering photorealistic images imitating the interactions of light.
 */
class Raytracer final {
    /// The amount of rays traced per pixel.
    int samples = 10;

    /// The amount of times a ray may scatter before having a contribution of zero.
    int max_depth = 10;

public:
    // Methods
    void Render(const shared_ptr<SphereList> &spheres, const shared_ptr<Camera> &camera, const shared_ptr<RenderTarget> &render_target) const {
        // Get RT_CAMERA_VALUES for ray query information
        auto rtcv = InitializeRTCamera(camera, render_target);

        // Rendered rows
        int rendered_rows = 0;

        for (int j = 0; j < render_target->get_height(); j++) {
            for (int i = 0; i < render_target->get_width(); i++) {
                vec3 color{0};

                for (int k = 0; k < samples; k++) {
                    Ray ray = GetRay(i, j, rtcv);
                    color += GetRayColor(ray, spheres, max_depth);
                }

                color /= samples;
                render_target->set_pixel(i, j, Color(color));
            }

            rendered_rows += 1;
            std::cout << "Rendering in progress: " << 100 * static_cast<float>(rendered_rows) / render_target->get_height() << "%\n";
        }
    }

    // Helpers
    /**
     * Initializes the camera values required for raytracing.
     * @param camera Camera to be rendering.
     * @param render_target Render target to be rendered to.
     * @return RT_CAMERA_VALUES struct.
     */
    static RT_CAMERA_VALUES InitializeRTCamera(const shared_ptr<Camera> &camera, const shared_ptr<RenderTarget> &render_target) {
        RT_CAMERA_VALUES rtc{};

        rtc.position = camera->get_position();
        rtc.direction = camera->get_look_at();
        rtc.up_direction = camera->get_up_direction();

        rtc.focal_length = length(rtc.position - rtc.direction);
        rtc.theta = degrees_to_radians(camera->get_fov());
        rtc.h = std::tan(rtc.theta / 2.0);
        rtc.viewport_height = 2.0 * rtc.h * rtc.focal_length;
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

    /**
     * Gets the ray coming from the camera through pixel (i, j).
     * @param i Pixel X position.
     * @param j Pixel Y position.
     * @param rtcv RT_CAMERA_VALUES struct.
     * @return Ray pointing through pixel (i, j).
     */
    [[nodiscard]] static Ray GetRay(const int i, const int j, const RT_CAMERA_VALUES &rtcv) {
        // Per pixel sample offset for antialiasing
        const auto offset = SampleSquare();
        const auto pixel_sample = rtcv.pixel_upper_left
                                  + ((i + offset.x) * rtcv.pixel_delta_u)
                                  + ((j + offset.y) * rtcv.pixel_delta_v);

        // Get ray through pixel by random offset for antialiasing
        const auto ray_origin = rtcv.position;
        const auto ray_direction = pixel_sample - ray_origin;

        // Return ray
        return {ray_origin, ray_direction};
    }

    /**
     * Gets a random point on the unit square, centered at (0, 0).
     * @return Random point on the unit square.
     */
    [[nodiscard]] static vec3 SampleSquare() {
        return {random_float() - 0.5, random_float() - 0.5, 0};
    }

    /**
     * Gets the visual color of a ray interacting with the world.
     * @param ray Ray of light.
     * @param spheres List of spheres to be rendered.
     * @param depth Recursion depth, amount of scattering allowed.
     * @return Color of ray interacting with the spheres.
     */
    [[nodiscard]] static vec3 GetRayColor(const Ray &ray, const shared_ptr<SphereList> &spheres, const int depth) {
        if (depth <= 0)
            return vec3(0);

        HitRecord record{};

        if (spheres->Hit(ray, 0.001, 1000000, record)) {
            Ray scattered{vec3(0), vec3(1)};
            vec3 attenuation;
            Scatter(ray, record, attenuation, scattered);
            return attenuation * GetRayColor(scattered, spheres, depth - 1);
        }

        // Sky rendering
        return skyColor(ray);
    }

    static vec3 skyColor(const Ray &rayIn) {
        const vec3 unit_direction = normalize(rayIn.get_direction());
        const auto a = 0.5f * (unit_direction.z + 1);
        const auto bottom_color = vec3(0, 0, 0);
        const auto top_color = vec3(1, 1, 1);
        return ((1.0f - a) * bottom_color) + (a * top_color);
    }

    static bool Scatter(const Ray &rayIn, const HitRecord &record, vec3 &attenuation, Ray &scattered) {
        vec3 direction = record.get_normal() + random_unit_vector();

        // Fix possible bug
        if (is_near_zero(direction))
            direction = record.get_normal();

        scattered = Ray(record.get_point(), direction);
        attenuation = record.get_color().get_color();

        return true;
    }

    // Getters and setters
    /**
     * Gets the number of samples.
     *
     * @return Amount of rays cast per pixel to be averaged in the final image.
     */
    [[nodiscard]] int get_samples() const {
        return samples;
    }

    /**
     * Sets the number of samples.
     *
     * @param samples Amount of rays cast per pixel to be averaged in the final image.
     */
    void set_samples(const int samples) {
        this->samples = samples;
    }

    /**
     * Gets the maximum depth.
     * @return Maximum number of scatters a ray can have before being terminated.
     */
    [[nodiscard]] int get_max_depth() const {
        return max_depth;
    }

    /**
     * Sets the maximum depth.
     * @param max_depth Maximum number of scatters a ray can have before being terminated.
     */
    void set_max_depth(const int max_depth) {
        this->max_depth = max_depth;
    }
};


#endif //RAYTRACER_H
