#include "Camera.h"

Camera::Camera(const vec3 &position, const vec3 &look_at) {
    set_position(position);
    set_look_at(look_at);
}

void Camera::set_position(const vec3 &position) {
    // Check if incoming position is valid
    if (!is_finite(position)) {
        throw CameraException("Camera::set_position(): position is not finite");
    }

    // Check if position is identical to look_at
    if (is_near_equal(position, get_look_at())) {
        throw CameraException("Camera::set_position(): position is too close to look_at");
    }

    // Set position
    this->position = position;
}

void Camera::set_look_at(const vec3 &look_at) {
    // Check if incoming look_at is valid
    if (!is_finite(look_at)) {
        throw CameraException("Camera::set_look_at(): look_at is not finite");
    }

    // Check if look_at is identical to position
    if (is_near_equal(look_at, get_position())) {
        throw CameraException("Camera::set_look_at(): look_at is too close to position");
    }

    // Set look_at
    this->look_at = look_at;
}

void Camera::set_up_direction(const vec3 &up_direction) {
    // Check if incoming up_direction is valid
    if (!is_finite(up_direction)) {
        throw CameraException("Camera::set_up_direction(): up_direction is not finite");
    }

    // Check if up_direction is a zero vector
    if (is_near_zero(up_direction)) {
        throw CameraException("Camera::set_up_direction(): up_direction is a zero vector");
    }

    // Set up_direction
    this->up_direction = up_direction;
}

void Camera::set_fov(const double fov) {
    // Check if incoming fov is valid
    if (!is_finite(fov)) {
        throw CameraException("Camera::set_fov(): fov is not finite");
    }

    // Ensure fov is within a proper range
    if (fov <= 0 || fov >= 180) {
        throw CameraException("Camera::set_fov(): fov should be between (0, 180) (non-inclusively)");
    }

    // Set fov
    this->fov = fov;
}
