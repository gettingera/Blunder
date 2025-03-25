#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Renderer.h"
#include "RenderTarget.h"
#include "Geometry/HitRecord.h"
#include "Scene/Scene.h"


class Raytracer final : public Renderer {
public:
    void Render(const shared_ptr<Scene> &scene, const shared_ptr<RenderTarget> &render_target) override {
        // Time to die
        for (int j = 0; j < render_target->get_height(); j++) {
            for (int i = 0; i < render_target->get_width(); i++) {
                auto color = dvec3(0);

                for (int k = 0; k < scene->camera->samples; k++) {
                    Ray ray = scene->camera->GetRay(i, j);
                    color += RayColor(ray, *scene->world);
                }

                render_target->SetPixel(i, j, color * (1.0 / scene->camera->samples));
            }
        }
    }

private:
    // Attributes
    int max_depth = 10;

    // Methods
    glm::dvec3 RayColor(const Ray &ray, const Hittable &world) {
        HitRecord record;

        if (world.Hit(ray, Interval(0, infinity), record)) {
            return 0.5 * (record.normal + glm::dvec3(1));
        }

        glm::dvec3 unitDirection = glm::normalize(ray.Direction());
        auto a = 0.5 * (unitDirection.y + 1.0);
        return (1.0 - a) * glm::dvec3(1.0) + a * glm::dvec3(0.5, 0.7, 1.0);
    }
};


#endif //RAYTRACER_H
