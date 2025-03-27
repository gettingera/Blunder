#ifndef HITRECORD_H
#define HITRECORD_H


/// Forward declaration of Material for compatibility
class Material;


/**
 * Storing information from ray-hittable intersections.
 *
 * This is useful for avoiding lengthy parameter lists.
 */
class HitRecord {
    /// Point of the ray-hittable intersection.
    dvec3 point{};

    /// Normal of the hittable at the intersection.
    dvec3 normal{};

    /// Material of the hittable.
    shared_ptr<Material> material{};

    /// Parameterized time when the Ray meets the hittable.
    double time{};

    /// Whether the ray intersected the hittable from the inside or outside.
    bool front_face{};

public:
    // Constructors
    /**
     * Creates a new HitRecord.
     */
    HitRecord() = default;

    // Methods
    /**
     * Calculates the front_face and normal from incoming ray and hittable normal information.
     *
     * @param ray The incoming Ray from the camera.
     * @param outwardNormal The outward facing normal from the hittable.
     */
    void SetFaceNormal(const Ray &ray, const dvec3 &outwardNormal) {
        front_face = dot(ray.get_direction(), outwardNormal) < 0;
        normal = front_face ? outwardNormal : -outwardNormal;
    }

    // Getters
    /**
     * Gets point.
     *
     * @return Point of the ray-hittable intersection.
     */
    [[nodiscard]] dvec3 get_point() const {
        return point;
    }

    /**
     * Gets normal.
     *
     * @return Normal of the hittable at the intersection.
     */
    [[nodiscard]] dvec3 get_normal() const {
        return normal;
    }

    /**
     * Gets material pointer.
     *
     * @return Material of the hittable.
     */
    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    /**
     * Gets time.
     *
     * @return Parameterized time when the Ray meets the hittable.
     */
    [[nodiscard]] double get_time() const {
        return time;
    }

    /**
     * Gets front_face.
     *
     * @return Whether the ray intersected the hittable from the inside or outside.
     */
    [[nodiscard]] bool get_front_face() const {
        return front_face;
    }

    // Setters
    /**
     * Sets point.
     *
     * @param point Point of the ray-hittable intersection.
     */
    void set_point(const dvec3 &point) {
        this->point = point;
    }

    /**
     * Sets normal.
     *
     * @param normal Normal of the hittable at the intersection.
     */
    void set_normal(const dvec3 &normal) {
        this->normal = normal;
    }

    /**
     * Sets material pointer.
     *
     * @param material Material of the hittable.
     */
    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }

    /**
     * Sets time.
     *
     * @param time Parameterized time when the Ray meets the hittable.
     */
    void set_time(const double time) {
        this->time = time;
    }

    /**
     * Sets front_face.
     *
     * @param front_face Whether the ray intersected the hittable from the inside or outside.
     */
    void set_front_face(const bool front_face) {
        this->front_face = front_face;
    }
};


#endif //HITRECORD_H
