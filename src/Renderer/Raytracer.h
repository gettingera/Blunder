#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Renderer.h"
#include "RenderTarget.h"
#include "Geometry/HitRecord.h"


class Raytracer : public Renderer {
  public:
    RenderTarget* Render(Scene* scene);

  private:
    // Methods
    glm::dvec3 RayColor(const Ray& ray, const Hittable& world);
};


#endif //RAYTRACER_H
