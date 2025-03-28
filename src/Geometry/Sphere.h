#ifndef SPHERE_H
#define SPHERE_H
#include <glm/gtx/norm.hpp>
#include "Hittable.h"


/**
 * Sphere object.
 *
 * Use this to render perfectly spherical objects.
 */
class Sphere final : public Hittable {
    /// Position of sphere.
    dvec3 center{};

    /// Radius of sphere.
    double radius{};

    /// Pointer to the sphere material.
    shared_ptr<Material> material;

public:
    // Constructors
    /**
     * Makes a new sphere.
     *
     * @param center Position of sphere.
     * @param radius Radius of sphere.
     * @param material Pointer to material.
     */
    Sphere(const dvec3 &center, const double radius, const shared_ptr<Material> &material) {
        set_center(center);
        set_radius(radius);
        set_material(material);
    }

    // Methods
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        dvec3 oc = center - ray.get_origin();
        auto a = length2(ray.get_direction());
        auto h = dot(ray.get_direction(), oc);
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
    /**
     * Gets center.
     *
     * @return Position of sphere.
     */
    [[nodiscard]] dvec3 get_center() const {
        return center;
    }

    /**
     * Gets radius.
     *
     * @return Radius of sphere.
     */
    [[nodiscard]] double get_radius() const {
        return radius;
    }

    /**
     * Gets pointer to material.
     * @return Pointer to material.
     */
    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    // Setters
    /**
     * Sets center.
     *
     * @param center Position of sphere.
     */
    void set_center(const dvec3 &center) {
        this->center = center;
    }

    /**
     * Sets radius.
     *
     * @param radius Radius of sphere.
     */
    void set_radius(const double radius) {
        this->radius = radius;
    }

    /**
     * Sets pointer to material.
     *
     * @param material Pointer to material.
     */
    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }
};


#endif //SPHERE_H
