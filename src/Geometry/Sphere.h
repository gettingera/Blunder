#ifndef SPHERE_H
#define SPHERE_H
#include <Utils/Headers.h>
#include "HitRecord.h"

/**
 * Sphere object.
 * Use this to render perfectly spherical objects.
 */
class Sphere final {
    /// Position of the position of the sphere.
    vec3 position{infinity, infinity, infinity};

    /// Radius of sphere.
    float radius{infinity};

    /// Color of the sphere
    Color color{0, 0, 0};

public:
    // Constructors
    /**
     * Makes a new stationary sphere.
     * @param position Position of sphere.
     * @param radius Radius of sphere.
     * @param color Color of the sphere.
     *
     * @note Test Cases: Constructor follows all setter qualifications. Just plug those values into the constructor.
     */
    Sphere(const vec3 &position, float radius, const Color &color);

    // Methods
    /**
     * Determines whether the incoming ray intersects the sphere or not.
     * If so, record the information in hitRecord and return true.
     * @param ray Ray that could possibly be intersecting the sphere.
     * @param tStart Minimum t value to begin checking.
     * @param tEnd Maximum t value to finish checking.
     * @param hitRecord Hit information if the ray intersects the sphere.
     * @return True if ray intersects sphere and logs information in hitRecord. False if there is no intersection.
     *
     * @note Test Cases:
     * Buckle up! You will need to check true / false. You can also check the hitRecord if you'd like.
     * auto s1 = Sphere(vec3(0, 0, 0), 1, Color(1, 1, 1))
     * auto ray = Ray(vec3(0, -1, 0), vec3(0, 1, 0))
     * auto hitRecord = HitRecord()
     * s1.Hit(ray, 0, 10000, hitRecord) -> true
     * ray.set_direction(0, -1, 0)
     * s1.Hit(ray, 0, 10000, hitRecord) -> false
     * s1.Hit(ray, 10000, 0, hitRecord) -> ERROR: will throw a SphereException (tStart is greater than tEnd)
     * s1.Hit(ray, -infinity, infinity, hitRecord) -> ERROR: will throw a SphereException (tStart and tEnd must be finite)
     */
    bool Hit(const Ray &ray, float tStart, float tEnd, HitRecord &hitRecord) const;

    // Getters
    /// Gets the position of the center of the sphere.
    [[nodiscard]] vec3 get_position() const { return position; }

    /// Gets the radius of the sphere.
    [[nodiscard]] float get_radius() const { return radius; }

    /// Gets the color of the sphere.
    [[nodiscard]] Color get_color() const { return color; }

    // Setters
    /**
     * Sets the center position of the sphere.
     * @param position Center position of the sphere.
     *
     * @note Test Cases:
     * auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1))
     * s1.set_position(vec3(1, 1, 1)) -> position should be (1, 1, 1)
     * s1.set_position(vec3(infinity, infinity, infinity)) -> ERROR: will throw a SphereException (position is not finite)
     */
    void set_position(const vec3 &position);

    /**
     * Sets the radius of the sphere.
     * @param radius Radius of the sphere.
     *
     * @note Test Cases:
     * auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1))
     * s1.set_radius(1) -> radius should be 1
     * s1.set_radius(0) -> ERROR: will throw a SphereException (radius should be greater than zero)
     * s1.set_radius(-1) -> ERROR: will throw a SphereException (radius should be greater than zero)
     * s1.set_radius(infinity) -> ERROR: will throw a SphereException (radius should be finite)
     */
    void set_radius(float radius);

    /**
     * Sets the color of the sphere.
     * @param color Color of the sphere.
     *
     * @note Test Cases:
     * auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1))
     * s1.set_color(Color(0.5, 0.5, 0.5)) -> color should be (0.5, 0.5, 0.5)
     */
    void set_color(const Color &color);
};


#endif //SPHERE_H
