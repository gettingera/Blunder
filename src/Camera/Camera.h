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

private:
    dvec3 position{};
    dvec3 direction{};
    dvec3 up_direction = dvec3(0, 0, 1);
    double vfov = 30;

    // // Methods
    // void Initialize() {
    //     // Initialize camera settings
    //     focal_length = glm::length(position - direction);
    //     theta = degrees_to_radians(vfov);
    //     h = std::tan(theta / 2.0);
    //     viewport_height = 2.0 * h * focal_length;
    //     viewport_width = viewport_height * (double(width) / (double(height)));
    //
    //     w = glm::normalize(position - direction);
    //     u = glm::normalize(glm::cross(up, w));
    //     v = glm::cross(w, u);
    //
    //     viewport_u = viewport_width * u;
    //     viewport_v = viewport_height * -v;
    //
    //     pixel_delta_u = viewport_u / double(width);
    //     pixel_delta_v = viewport_v / double(height);
    //
    //     viewport_upper_left = position - (focal_length * w) - viewport_u / 2.0 - viewport_v / 2.0;
    //     pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    // }
    //
    // Ray GetRay(int i, int j) const {
    //     auto offset = SampleSquare();
    //     auto pixel_sample = pixel00_loc
    //                         + ((i + offset.x) * pixel_delta_u)
    //                         + ((j + offset.y) * pixel_delta_v);
    //
    //     auto ray_origin = position;
    //     auto ray_direction = pixel_sample - ray_origin;
    //
    //     return Ray(ray_origin, ray_direction);
    // }
    //
    // glm::dvec3 SampleSquare() const {
    //     return glm::dvec3(random_double() - 0.5, random_double() - 0.5, 0);
    // }
};


#endif //CAMERA_H
