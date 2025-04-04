#ifndef RAY_H
#define RAY_H
#include <Utils/Headers.h>

/**
 * Ray class for defining and operating with rays.
 * Rays have a starting position and a direction (distinct).
 * Different points along this ray can be found by using a parameter t.
 * This is useful for calculating intersections of objects in terms of one variable, t.
 */
class Ray {
    /// Position of ray position.
    vec3 position{infinity, infinity, infinity};

    /// Position of ray direction.
    vec3 direction{infinity, infinity, infinity};

public:
    // Constructors
    /**
     * Makes a new ray.
     * @param position Position.
     * @param direction Direction.
     *
     * @note Test Cases:
     * auto r1 = Ray(vec3(0, 0, 0), vec3(1, 1, 1)) -> position should be (0, 0, 0), direction should be (1, 1, 1)
     * auto r2 = Ray(vec3(1, 1, 1), vec3(0, 0, 0)) -> ERROR: will throw a RayException (direction vector should be non-zero)
     */
    Ray(const vec3 &position, const vec3 &direction);

    // Methods
    /**
     * Gets the point on the ray at the parameter t.
     * @param t Finite, real valued parameter.
     * @return Point on ray at t. (using the equation: position + t*direction)
     *
     * @note Test Cases:
     * auto r1 = Ray(vec3(0, 0, 0), vec3(1, 1, 1))
     * r1.at(0) -> should be equal to r1.position
     * r1.at(1) -> should be equal to r1.position + r1.direction
     * r1.at(infinity) -> ERROR: will throw a RayException (t must be finite)
     * r1.at(NAN) -> ERROR: will throw a RayException (t must be finite)
     */
    [[nodiscard]] vec3 at(float t) const;

    // Getters
    /// Gets the starting position of the ray.
    [[nodiscard]] vec3 get_position() const { return position; }

    /// Gets the direction vector the ray is traveling.
    [[nodiscard]] vec3 get_direction() const { return direction; }

    // Setters
    /**
     * Sets position.
     * @param position Starting position of the ray.
     *
     * @notes Test Cases:
     * auto r1 = Ray(vec3(0, 0, 0), vec3(1, 1, 1))
     * r1.set_position(vec3(1, 1, 1)) -> position should be (1, 1, 1)
     */
    void set_position(const vec3 &position);

    /**
     * Sets direction.
     * @param direction Direction the ray travels.
     *
    * * @notes Test Cases:
     * auto r1 = Ray(vec3(0, 0, 0), vec3(1, 1, 1))
     * r1.set_direction(vec3(2, 2, 2)) -> direction should be (2, 2, 2)
     * r1.set_direction(vec3(0, 0, 0)) -> ERROR: will throw a RayException (direction cannot be a zero vector)
     */
    void set_direction(const vec3 &direction);
};

#endif //RAY_H
