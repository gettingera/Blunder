#ifndef HITRECORD_H
#define HITRECORD_H


/// Forward declaration of Material for compatibility
class Material;


/**
 * Stores information from ray-hittable intersections.
 *
 * This is useful for avoiding lengthy parameter lists.
 */
class HitRecord {
    /// Point of intersection.
    dvec3 point{};

    /// Surface normal at the intersection.
    dvec3 normal{};

    /// Material of the intersected object.
    shared_ptr<Material> material{};

    /// Ray parameter at intersection.
    double time{};

    /// Whether the intersection was from inside or outside.
    bool front_face{};

public:
    // Constructors
    /**
     * Creates a new HitRecord.
     */
    HitRecord() = default;

    // Methods
    /**
     * Computes intersection normal direction based on ray and surface normal.
     *
     * @param ray The incoming ray.
     * @param outwardNormal The outward-facing surface normal.
     */
    void SetFaceNormal(const Ray &ray, const dvec3 &outwardNormal) {
        set_front_face(dot(ray.get_direction(), outwardNormal) < 0);
        set_normal(get_front_face() ? outwardNormal : -outwardNormal);
    }

    // Getters
    /**
     * Gets the intersection point.
     *
     * @return Point of intersection.
     */
    [[nodiscard]] dvec3 get_point() const {
        return point;
    }

    /**
     * Gets the surface normal.
     *
     * @return Surface normal at the intersection.
     */
    [[nodiscard]] dvec3 get_normal() const {
        return normal;
    }

    /**
     * Gets the material.
     *
     * @return Material of the intersected object.
     */
    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    /**
     * Gets the ray parameter.
     *
     * @return Ray parameter at intersection.
     */
    [[nodiscard]] double get_time() const {
        return time;
    }

    /**
     * Gets the intersection orientation.
     *
     * @return Whether the intersection was from inside or outside.
     */
    [[nodiscard]] bool get_front_face() const {
        return front_face;
    }

    // Setters
    /**
     * Sets the intersection point.
     *
     * @param point Point of intersection.
     */
    void set_point(const dvec3 &point) {
        this->point = point;
    }

    /**
     * Sets the surface normal.
     *
     * @param normal Surface normal at the intersection.
     */
    void set_normal(const dvec3 &normal) {
        this->normal = normal;
    }

    /**
     * Sets the material.
     *
     * @param material Material of the intersected object.
     */
    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }

    /**
     * Sets the ray parameter.
     *
     * @param time Ray parameter at intersection.
     */
    void set_time(const double time) {
        this->time = time;
    }

    /**
     * Sets the intersection orientation.
     *
     * @param front_face Whether the intersection was from inside or outside.
     */
    void set_front_face(const bool front_face) {
        this->front_face = front_face;
    }
};


#endif //HITRECORD_H
