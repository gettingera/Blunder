#ifndef CAMERA_H
#define CAMERA_H


class Camera {
public:
    // Constructor
    Camera(const dvec3 &position, const dvec3 &direction, const dvec3 &up_direction) {
        set_position(position);
        set_direction(direction);
        set_up_direction(up_direction);
    }

    // Getters
    [[nodiscard]] dvec3 get_position() const {
        return position;
    }

    [[nodiscard]] dvec3 get_direction() const {
        return direction;
    }

    [[nodiscard]] dvec3 get_up_direction() const {
        return up_direction;
    }

    [[nodiscard]] double get_vfov() const {
        return vfov;
    }

    [[nodiscard]] double get_focus_distance() const {
        return focus_distance;
    }

    [[nodiscard]] double get_focus_angle() const {
        return focus_angle;
    }

    // Setters
    void set_position(const dvec3 &position) {
        this->position = position;
    }

    void set_direction(const dvec3 &direction) {
        this->direction = direction;
    }

    void set_up_direction(const dvec3 &up_direction) {
        this->up_direction = up_direction;
    }

    void set_vfov(const double vfov) {
        this->vfov = vfov;
    }

    void set_focus_distance(const double focus_distance) {
        this->focus_distance = focus_distance;
    }

    void set_focus_angle(const double focus_angle) {
        this->focus_angle = focus_angle;
    }

private:
    dvec3 position{};
    dvec3 direction{};
    dvec3 up_direction = dvec3(0, 0, 1);
    double vfov = 20;
    double focus_distance = 0;
    double focus_angle = 0;
};


#endif //CAMERA_H
