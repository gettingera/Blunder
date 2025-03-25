#ifndef RAY_H
#define RAY_H


class Ray {
public:
    // Constructor
    Ray(const dvec3 &origin, const dvec3 &direction) {
        set_origin(origin);
        set_direction(direction);
    }

    // Methods
    [[nodiscard]] dvec3 At(const double time) const {
        return Origin() + (Direction() * time);
    }

    // Getters
    [[nodiscard]] const dvec3 &Origin() const { return origin; }
    [[nodiscard]] const dvec3 &Direction() const { return direction; }

    // Setters
    void set_origin(const dvec3 &origin) {
        this->origin = origin;
    }

    void set_direction(const dvec3 &direction) {
        this->direction = direction;
    }

private:
    // Attributes
    dvec3 origin{}, direction{};
};


#endif //RAY_H
