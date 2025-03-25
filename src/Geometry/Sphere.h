#ifndef SPHERE_H
#define SPHERE_H


#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include "Hittable.h"


class Sphere : public Hittable {
    public:
      Sphere(const glm::dvec3& center, double radius) : center(center), radius(radius) {}

      bool Hit(const Ray& ray, double timeMin, double timeMax, HitRecord& record) const override {
          glm::dvec3 oc = this->center - ray.Origin();
          auto a = glm::length2(ray.Direction());
          auto h = glm::dot(ray.Direction(), oc);
          auto c = glm::length2(oc) - radius*radius;

          auto discriminant = h*h - a*c;
          if (discriminant < 0)
              return false;

          auto sqrtd = std::sqrt(discriminant);

          // Find the nearest root that lies in the acceptable range.
          auto root = (h - sqrtd) / a;
          if (root <= timeMin || timeMax <= root) {
              root = (h + sqrtd) / a;
              if (root <= timeMin || timeMax <= root)
                  return false;
          }

          record.time = root;
          record.point = ray.At(record.time);
          record.normal = (rec.p - center) / radius;

          return true;
      }

    private:
        glm::dvec3 center;
        double radius;
};



#endif //SPHERE_H
