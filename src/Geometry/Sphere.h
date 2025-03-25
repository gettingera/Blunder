#ifndef SPHERE_H
#define SPHERE_H


#include <glm/gtx/norm.hpp>
#include "Hittable.h"


class Sphere final : public Hittable {
public:
    // Constructors
    Sphere(const dvec3 &center, const double radius, const shared_ptr<Material> &material) {
        set_center(center);
        set_radius(radius);
        set_material(material);
    }

    // Methods
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        dvec3 oc = center - ray.Origin();
        auto a = length2(ray.Direction());
        auto h = dot(ray.Direction(), oc);
        auto c = length2(oc) - radius * radius;

        auto discriminant = h * h - a * c;
        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if (!rayTime.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!rayTime.surrounds(root))
                return false;
        }

        record.set_time(root);
        record.set_point(ray.At(record.get_time()));
        const dvec3 outward_normal = (record.get_point() - center) / radius;
        record.SetFaceNormal(ray, outward_normal);
        record.set_material(material);

        return true;
    }

    // Getters
    [[nodiscard]] dvec3 get_center() const {
        return center;
    }

    [[nodiscard]] double get_radius() const {
        return radius;
    }

    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    // Setters
    void set_center(const dvec3 &center) {
        this->center = center;
    }

    void set_radius(const double radius) {
        this->radius = radius;
    }

    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }

private:
    // Attributes
    dvec3 center {};
    double radius {};
    shared_ptr<Material> material;
};


#endif //SPHERE_H
