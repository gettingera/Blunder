#ifndef RAY_H
#define RAY_H


class Ray {
public:
    // Constructors
    /**
     * Creates a new Ray.
     */
    Ray() = default;

    Ray(const dvec3 &origin, const dvec3 &direction) {
        set_origin(origin);
        set_direction(direction);
    }

    // Methods
    [[nodiscard]] dvec3 At(const double time) const {
        return get_origin() + (get_direction() * time);
    }

    // Getters
    [[nodiscard]] const dvec3 &get_origin() const { return origin; }

    [[nodiscard]] const dvec3 &get_direction() const { return direction; }

    // Setters
    void set_origin(const dvec3 &origin) {
        this->origin = origin;
    }

    void set_direction(const dvec3 &direction) {
        this->direction = direction;
    }

private:
    // Attributes
    dvec3 origin{};
    dvec3 direction{};
};


#endif //RAY_H
