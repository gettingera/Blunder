#ifndef RAY_H
#define RAY_H


/**
 * Ray class for defining and operating with rays.
 *
 * Useful for defining camera rays, light rays, intersection tests, and parameterization.
 */
class Ray {
    /// Position of ray origin.
    dvec3 origin{};

    /// Position of ray direction.
    dvec3 direction{};

public:
    // Constructors
    Ray() = default;

    /**
     * Makes a new ray.
     *
     * @param origin Origin.
     * @param direction Direction.
     */
    Ray(const dvec3 &origin, const dvec3 &direction) {
        set_origin(origin);
        set_direction(direction);
    }

    // Methods
    /**
     * Gets the point on the ray at the time parameter.
     *
     * @param time Time parameter.
     * @return Point on ray.
     */
    [[nodiscard]] dvec3 At(const double time) const {
        return get_origin() + (get_direction() * time);
    }

    // Getters
    /**
     * Gets origin.
     *
     * @return Origin.
     */
    [[nodiscard]] const dvec3 &get_origin() const {
        return origin;
    }

    /**
     * Gets direction.
     *
     * @return Direction.
     */
    [[nodiscard]] const dvec3 &get_direction() const {
        return direction;
    }

    // Setters
    /**
     * Sets origin.
     *
     * @param origin Origin.
     */
    void set_origin(const dvec3 &origin) {
        this->origin = origin;
    }

    /**
     * Sets direction.
     *
     * @param direction Direction.
     */
    void set_direction(const dvec3 &direction) {
        this->direction = direction;
    }
};


#endif //RAY_H
