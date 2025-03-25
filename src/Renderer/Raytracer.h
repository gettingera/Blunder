#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Renderer.h"
#include "RenderTarget.h"
#include "Geometry/HitRecord.h"
#include "Scene/Scene.h"


struct RT_CAMERA_VALUES {
    double focal_length;
    double theta;
    double h;
    double viewport_height;
    double viewport_width;

    dvec3 position;
    dvec3 direction;
    dvec3 up_direction;
    dvec3 u;
    dvec3 v;
    dvec3 w;
    dvec3 viewport_u;
    dvec3 viewport_v;
    dvec3 pixel_delta_u;
    dvec3 pixel_delta_v;
    dvec3 viewport_upper_left;
    dvec3 pixel_upper_left;
};


class Raytracer final : public Renderer {
public:
    // Methods
    void Render(const Scene &scene, const shared_ptr<RenderTarget> &render_target) override {
        // Get RT_CAMERA_VALUES for ray query information
        auto rtcv = InitializeRTCamera(scene, render_target);


        for (int j = 0; j < render_target->get_height(); j++) {
            for (int i = 0; i < render_target->get_width(); i++) {
                auto color = dvec3(0);

                for (int k = 0; k < samples; k++) {
                    Ray ray = GetRay(i, j, rtcv);
                    color += GetRayColor(ray, scene.world);
                }

                color /= samples;
                render_target->SetPixel(i, j, color);
            }
        }
    }

    // Helpers
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

        return rtc;
    }

    [[nodiscard]] static Ray GetRay(const int i, const int j, const RT_CAMERA_VALUES &rtcv) {
        const auto offset = SampleSquare();
        const auto pixel_sample = rtcv.pixel_upper_left
                                  + ((i + offset.x) * rtcv.pixel_delta_u)
                                  + ((j + offset.y) * rtcv.pixel_delta_v);

        const auto ray_origin = rtcv.position;
        const auto ray_direction = pixel_sample - ray_origin;

        return {ray_origin, ray_direction};
    }

    [[nodiscard]] static dvec3 SampleSquare() {
        return {random_double() - 0.5, random_double() - 0.5, 0};
    }

    [[nodiscard]] static dvec3 GetRayColor(const Ray &ray, const shared_ptr<Hittable> &world) {
        HitRecord record{};

        if (world->Hit(ray, Interval(0, infinity), record)) {
            return 0.5 * (record.get_normal() + dvec3(1));
        }

        dvec3 unit_direction = normalize(ray.Direction());
        auto a = 0.5 * (unit_direction.y + 1.0);
        return (1.0 - a) * dvec3(1) + a * dvec3(0.5, 0.7, 1);
    }

private:
    int samples = 10;
};


#endif //RAYTRACER_H
