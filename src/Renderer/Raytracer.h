#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "Renderer.h"
#include "RenderTarget.h"
#include "Geometry/HitRecord.h"
#include "Materials/Material.h"
#include "Scene/Scene.h"


/**
 * Utility structure to hold necessary camera values and computations for ray tracing.
 *
 * Values are largely undocumented for now. They will be documented soon. UNFINISHED.
 */
struct RT_CAMERA_VALUES {
    double focal_length;
    double theta;
    double h;
    double viewport_height;
    double viewport_width;
    double focus_distance;
    double focus_angle;

    dvec3 position;
    dvec3 direction;
    dvec3 up_direction;
    dvec3 u;
    dvec3 v;
    dvec3 w;
    dvec3 focus_disk_u;
    dvec3 focus_disk_v;
    dvec3 viewport_u;
    dvec3 viewport_v;
    dvec3 pixel_delta_u;
    dvec3 pixel_delta_v;
    dvec3 viewport_upper_left;
    dvec3 pixel_upper_left;
};


/**
 * Raytracer renderer.
 *
 * Useful for rendering photorealistic images imitating the interactions of light.
 */
class Raytracer final : public Renderer {
    /// The amount of rays traced per pixel.
    int samples = 10;

    /// The amount of times a ray may scatter before having a contribution of zero.
    int max_depth = 10;

public:
    // Methods
    void Render(const Scene &scene, const shared_ptr<RenderTarget> &render_target) override {
        // Get RT_CAMERA_VALUES for ray query information
        auto rtcv = InitializeRTCamera(scene, render_target);


        for (int j = 0; j < render_target->get_height(); j++) {
            std::cout << "Rendering in progress: " << 100 * static_cast<double>(j) / render_target->get_height() <<
                    "%\n";

            for (int i = 0; i < render_target->get_width(); i++) {
                auto color = dvec3(0);

                for (int k = 0; k < samples; k++) {
                    Ray ray = GetRay(i, j, rtcv);
                    color += GetRayColor(ray, scene.world, max_depth);
                }

                color /= samples;
                render_target->SetPixel(i, j, color);
            }
        }
    }

    // Helpers
    /**
     * Initializes the camera values required for raytracing.
     *
     * @param scene Scene to be rendered.
     * @param render_target Render target to be rendered to.
     * @return RT_CAMERA_VALUES struct.
     */
    static RT_CAMERA_VALUES InitializeRTCamera(const Scene &scene, const shared_ptr<RenderTarget> &render_target) {
        RT_CAMERA_VALUES rtc{};

        rtc.position = scene.camera->get_position();
        rtc.direction = scene.camera->get_direction();
        rtc.up_direction = scene.camera->get_up_direction();

        rtc.focal_length = length(rtc.position - rtc.direction);
        rtc.theta = degrees_to_radians(scene.camera->get_vfov());
        rtc.h = std::tan(rtc.theta / 2.0);
        rtc.viewport_height = 2.0 * rtc.h * rtc.focal_length;
        rtc.viewport_width = rtc.viewport_height * (
                                 static_cast<double>(render_target->get_width()) / static_cast<double>(render_target->
                                     get_height()));

        rtc.w = normalize(rtc.position - rtc.direction);
        rtc.u = normalize(cross(rtc.up_direction, rtc.w));
        rtc.v = cross(rtc.w, rtc.u);

        rtc.viewport_u = rtc.viewport_width * rtc.u;
        rtc.viewport_v = rtc.viewport_height * -rtc.v;

        rtc.pixel_delta_u = rtc.viewport_u / static_cast<double>(render_target->get_width());
        rtc.pixel_delta_v = rtc.viewport_v / static_cast<double>(render_target->get_height());

        rtc.viewport_upper_left = scene.camera->get_position() - (rtc.focal_length * rtc.w) - rtc.viewport_u / 2.0 - rtc
                                  .viewport_v / 2.0;
        rtc.pixel_upper_left = rtc.viewport_upper_left + 0.5 * (rtc.pixel_delta_u + rtc.pixel_delta_v);

        auto focus_radius = scene.camera->get_focus_distance() * std::tan(
                                degrees_to_radians(scene.camera->get_focus_angle() / 2));
        rtc.focus_disk_u = rtc.u * focus_radius;
        rtc.focus_disk_v = rtc.v * focus_radius;

        rtc.focus_distance = scene.camera->get_focus_distance();
        rtc.focus_angle = scene.camera->get_focus_angle();

        return rtc;
    }

    /**
     * Gets the ray coming from the camera through pixel (i, j).
     *
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

        // Used for depth of field, offsets ray origin by focus angle
        const auto ray_origin = (rtcv.focus_angle <= 0) ? rtcv.position : focus_disk_sample(rtcv);
        const auto ray_direction = pixel_sample - ray_origin;

        // Random double between 0 and 1 for motion blur
        const auto ray_time = random_double();
        return {ray_origin, ray_direction, ray_time};
    }

    /**
     * Gets a random point on the focus disk for rendering depth of field.
     *
     * @param rtcv RT_CAMERA_VALUES struct.
     * @return Point on focus disk.
     */
    [[nodiscard]] static dvec3 focus_disk_sample(const RT_CAMERA_VALUES &rtcv) {
        auto p = random_in_unit_disk();
        return rtcv.position + (p.x * rtcv.focus_disk_u) + (p.y * rtcv.focus_disk_v);
    }

    /**
     * Gets a random point on the unit square, centered at (0, 0).
     *
     * @return Random point on the unit square.
     */
    [[nodiscard]] static dvec3 SampleSquare() {
        return {random_double() - 0.5, random_double() - 0.5, 0};
    }

    /**
     * Gets the visual color of a ray interacting with the world.
     *
     * @param ray Ray of light.
     * @param world List of objects to be rendered.
     * @param depth Recursion depth, amount of scattering allowed.
     * @return Color of ray interacting with the world.
     */
    [[nodiscard]] static dvec3 GetRayColor(const Ray &ray, const shared_ptr<Hittable> &world, const int depth) {
        if (depth <= 0)
            return dvec3(0);

        HitRecord record{};

        if (world->Hit(ray, Interval(0.001, infinity), record)) {
            Ray scattered;
            dvec3 attenuation;

            if (record.get_material()->Scatter(ray, record, attenuation, scattered)) {
                return attenuation * GetRayColor(scattered, world, depth - 1);
            }

            return dvec3(0);
        }

        // Sky rendering
        const dvec3 unit_direction = normalize(ray.get_direction());
        const auto a = 0.5 * (unit_direction.z + 1);
        return (1.0 - a) * dvec3(0.8, 0.9, 1.0) + a * dvec3(0.4, 0.8, 1.0);
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
