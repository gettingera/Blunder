#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Renderer.h"
#include "RenderTarget.h"
#include "Geometry/HitRecord.h"
#include "Scene/Scene.h"


class Raytracer : public Renderer {
public:
    std::shared_ptr<RenderTarget> Render(std::shared_ptr<Scene> scene) override {
        // Future, pass pointer to rendertarget
        auto image = std::make_shared<RenderTarget>(scene->settings->width, scene->settings->height);

        // Time to die


        return image;
    }

private:
    // Attributes

    // Methods
    glm::dvec3 RayColor(const Ray &ray, const Hittable &world) {
        HitRecord record;

        if (world.Hit(ray, Interval(0, infinity), record)) {
            return 0.5 * (record.normal + glm::dvec3(1));
        }

        glm::dvec3 unitDirection = glm::normalize(ray.Direction());
        auto a = 0.5 * (unitDirection.y + 1.0);
        return (1.0-a)*glm::dvec3(1.0); + a*glm::dvec3(0.5, 0.7, 1.0);

    }
};


#endif //RAYTRACER_H
