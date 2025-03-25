#ifndef CAMERA_H
#define CAMERA_H


class Camera {
public:
    // Where I am, where I am looking to
    glm::dvec3 position;
    glm::dvec3 direction;
    glm::dvec3 up = glm::dvec3(0, 0, 1);

    double vfov = 90;

    int width = 100;
    int height = 100;
    int samples = 2;

    // Methods
    void Initialize() {
        // Initialize camera settings
        focal_length = glm::length(position - direction);
        theta = degrees_to_radians(vfov);
        h = std::tan(theta / 2.0);
        viewport_height = 2.0 * h * focal_length;
        viewport_width = viewport_height * (double(width) / (double(height)));

        w = glm::normalize(position - direction);
        u = glm::normalize(glm::cross(up, w));
        v = glm::cross(w, u);

        viewport_u = viewport_width * u;
        viewport_v = viewport_height * -v;

        pixel_delta_u = viewport_u / double(width);
        pixel_delta_v = viewport_v / double(height);

        viewport_upper_left = position - (focal_length * w) - viewport_u / 2.0 - viewport_v / 2.0;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    Ray GetRay(int i, int j) const {
        auto offset = SampleSquare();
        auto pixel_sample = pixel00_loc
                            + ((i + offset.x) * pixel_delta_u)
                            + ((j + offset.y) * pixel_delta_v);

        auto ray_origin = position;
        auto ray_direction = pixel_sample - ray_origin;

        return Ray(ray_origin, ray_direction);
    }

    glm::dvec3 SampleSquare() const {
        return glm::dvec3(random_double() - 0.5, random_double() - 0.5, 0);
    }

private:
    // Temporary
    double focal_length, theta, h, viewport_height, viewport_width, pixel_samples_scale;
    glm::dvec3 u, v, w, viewport_u, viewport_v, pixel_delta_u, pixel_delta_v, viewport_upper_left, pixel00_loc;
};


#endif //CAMERA_H
