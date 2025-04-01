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
    /// Position of sphere over frame beginning to frame ending.
    Ray center{};

    /// Radius of sphere.
    double radius{};

    /// Pointer to the sphere material.
    shared_ptr<Material> material;

    /// Bounding box of the sphere.
    AABB bounding_box;

public:
    // Constructors
    /**
     * Makes a new stationary sphere.
     *
     * @param center Position of sphere.
     * @param radius Radius of sphere.
     * @param material Pointer to material.
     */
    Sphere(const dvec3 &center, const double radius, const shared_ptr<Material> &material) {
        set_center(Ray(center, dvec3(0)));
        set_radius(radius);
        set_material(material);

        // Sets bounding box of stationary sphere.
        auto rvec = dvec3(radius);
        set_bounding_box(AABB(get_center().get_origin() - rvec, get_center().get_origin() + rvec));
    }

    /**
     * Makes a new moving sphere.
     *
     * @param center1 Position of the sphere at frame beginning.
     * @param center2 Position of the sphere at frame ending.
     * @param radius Radius of sphere.
     * @param material Pointer to material.
     */
    Sphere(const dvec3 &center1, const dvec3 &center2, const double radius, const shared_ptr<Material> &material) {
        set_center(Ray(center1, center2 - center1));
        set_radius(radius);
        set_material(material);

        // Sets bounding box of moving sphere.
        auto rvec = dvec3(radius);
        AABB box1(get_center().At(0) - rvec, get_center().At(0) + rvec);
        AABB box2(get_center().At(1) - rvec, get_center().At(1) + rvec);
        set_bounding_box(AABB(box1, box2));
    }

    // Methods
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        dvec3 current_center = get_center().At(ray.get_time());
        dvec3 oc = current_center - ray.get_origin();
        auto a = length2(ray.get_direction());
        auto h = dot(ray.get_direction(), oc);
        auto c = length2(oc) - get_radius() * get_radius();

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
        const dvec3 outward_normal = (record.get_point() - current_center) / get_radius();
        record.SetFaceNormal(ray, outward_normal);
        record.set_material(get_material());

        return true;
    }

    [[nodiscard]] AABB BoundingBox() const override {
        return get_bounding_box();
    };

    // Getters
    /**
     * Gets center.
     *
     * @return Position of sphere.
     */
    [[nodiscard]] Ray get_center() const {
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

    /**
     * Gets the bounding box.
     * @return Bounding box surrounding the sphere.
     */
    [[nodiscard]] AABB get_bounding_box() const {
        return bounding_box;
    }

    // Setters
    /**
     * Sets center.
     *
     * @param center Position of sphere.
     */
    void set_center(const Ray &center) {
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

    /**
     * Sets the bounding box.
     *
     * @param bounding_box Bounding box surrounding the sphere.
     */
    void set_bounding_box(const AABB &bounding_box) {
        this->bounding_box = bounding_box;
    }
};


#endif //SPHERE_H
