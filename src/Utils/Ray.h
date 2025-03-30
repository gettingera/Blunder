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

    /// Time when the ray is, using the equation origin + direction * time. Used for motion blur.
    double time{0};

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

    /**
     * Makes a new ray, with a time variable for motion blur.
     *
     * @param origin Origin.
     * @param direction Direction.
     * @param time Time along the ray for motion blur calculations.
     */
    Ray(const dvec3 &origin, const dvec3 &direction, const double time) {
        set_origin(origin);
        set_direction(direction);
        set_time(time);
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

    /**
     * Gets time.
     *
     * @return Time when ray is along its direction vector.
     */
    [[nodiscard]] double get_time() const {
        return time;
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

    /**
     * Sets time.
     * @param time Time when ray is along its direction vector.
     */
    void set_time(const double time) {
        this->time = time;
    }
};


#endif //RAY_H
