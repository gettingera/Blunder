#ifndef HITRECORD_H
#define HITRECORD_H
#include <Utils/Headers.h>

/**
 * Stores information from ray-hittable intersections.
 * This is useful for avoiding lengthy parameter lists.
 */
class HitRecord {
    /// Point of intersection.
    vec3 point{infinity, infinity, infinity};

    /// Surface normal at the intersection.
    vec3 normal{infinity, infinity, infinity};

    /// Color of point of intersection
    Color color{0, 0, 0};

    /// Ray parameter t at point of intersection.
    double t{infinity};

public:
    // Constructors
    /**
     * Creates a new HitRecord.
     */
    HitRecord() = default;

    // Getters
    /// Gets the intersection point.
    [[nodiscard]] vec3 get_point() const { return point; }

    /// Gets the surface normal.
    [[nodiscard]] vec3 get_normal() const { return normal; }

    /// Gets the color of the point of intersection.
    [[nodiscard]] Color get_color() const { return color; }

    /// Gets the ray parameter t.
    [[nodiscard]] double get_t() const { return t; }

    // Setters
    /**
     * Sets the intersection point.
     * @param point Point of intersection.
     *
     * @note Test Cases:
     * auto hr1 = HitRecord()
     * hr1.set_point(vec3(0, 0, 0)) -> point should be (0, 0, 0)
     * hr1.set_point(vec3(infinity, infinity, infinity)) -> ERROR: will throw a HitRecordException (point is not finite)
     */
    void set_point(const vec3 &point);

    /**
     * Sets the surface normal.
     * @param normal Surface normal at the intersection.
     *
     * @note Test Cases:
     * auto hr1 = HitRecord()
     * hr1.set_normal(vec3(1, 1, 1)) -> point should be normalize((1, 1, 1))
     * hr1.set_normal(vec3(0, 0, 0)) -> ERROR: will throw a HitRecordException (normal cannot be a zero vector)
     * hr1.set_normal(vec3(infinity, infinity, infinity)) -> ERROR: will throw a HitRecordException (normal is not finite)
     */
    void set_normal(const vec3 &normal);

    /**
     * Sets the color of the point of intersection.
     * @param color Color at the point of intersection.
     *
     * @note Test Cases:
     * auto hr1 = HitRecord()
     * hr1.set_color(Color(0.5, 0.5, 0.5)) -> color should be Color(0.5, 0.5, 0.5)
     */
    void set_color(const Color &color);

    /**
     * Sets the ray parameter.
     * @param t Ray parameter at intersection.
     *
     * @note Test Cases:
     * auto hr1 = HitRecord()
     * hr1.set_t(1) -> t should be 1
     * hr1.set_t(0) -> t should be 0
     * hr1.set_t(infinity) -> ERROR: will throw a HitRecordException (t is not finite)
     */
    void set_t(double t);
};


#endif //HITRECORD_H
