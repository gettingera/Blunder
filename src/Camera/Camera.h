#ifndef CAMERA_H
#define CAMERA_H
#include <Utils/Headers.h>

/**
 * A camera for viewing and rendering 3D scenes.
 * This positionable camera provides utilities for safe manipulation of the camera.
 */
class Camera {
    /// World position of camera.
    vec3 position{-infinity, -infinity, -infinity};

    /// Position in the world the camera is viewing.
    vec3 look_at{infinity, infinity, infinity};

    /// Vector indicating what direction should be considered upward.
    vec3 up_direction{0, 0, 1};

    /// Vertical FOV for zooming the camera in and out.
    float fov{45};

public:
    // Constructors
    /**
     * Creates a new camera.
     * @param position Position of the camera in the world.
     * @param look_at Position the camera is looking at in the world.
     *
     * @note
     * Test Cases:\n
     * auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1)); -> position should be (0, 0, 0), look_at should be (1, 1, 1)\n
     * auto c2 = Camera(vec3(0, 0, 0), vec3(0, 0, 0)); -> ERROR: will throw a CameraException (equal vectors should fail)\n
     */
    Camera(const vec3 &position, const vec3 &look_at);

    // Getters
    /// Gets the position of the camera in the world.
    [[nodiscard]] vec3 get_position() const { return position; }

    /// Gets the position the camera is looking at in the world.
    [[nodiscard]] vec3 get_look_at() const { return look_at; }

    /// Gets the direction considered upward in the world.
    [[nodiscard]] vec3 get_up_direction() const { return up_direction; }

    /// Gets the vertical field of view of the camera.
    [[nodiscard]] float get_fov() const { return fov; }

    // Setters
    /**
     * Sets the position of the camera in the world.
     * @param position Position of the camera in the world.
     *
     * @note Test Cases:\n
     * auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1)) -> makes a new camera\n
     * c1.set_position(vec3(2, 2, 2)) -> position should be (2, 2, 2)\n
     * c1.set_position(vec3(1, 1, 1)) -> ERROR: will throw a CameraException (position must not be equal to look_at)\n
     */
    void set_position(const vec3 &position);

    /**
     * Gets the position in the world the camera is viewing.
     * @param look_at Position in the world the camera is viewing.
     *
     * @note Test Cases:\n
     * auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1))\n
     * c1.set_look_at(vec3(2, 2, 2)) -> look_at should be (2, 2, 2)\n
     * c1.set_look_at(vec3(0, 0, 0)) -> ERROR: will throw a CameraException (look_at must not be equal to position)\n
     */
    void set_look_at(const vec3 &look_at);

    /**
     * Sets the vector indicating what direction should be considered upward.
     * @param up_direction Vector indicating what direction should be considered upward.
     *
     * @note Test Cases:\n
     * auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1))\n
     * c1.set_up_direction(vec3(1, 2, 3)) -> up_direction should be (1, 2, 3)\n
     * c1.set_up_direction(vec3(0, 0, 0)) -> ERROR: will throw a CameraException (up_direction must not be a zero vector)\n
     */
    void set_up_direction(const vec3 &up_direction);

    /**
     * Sets the vertical field of to a value between (0, 180) degrees.
     * @param fov Vertical FOV for zooming the camera in and out.
     *
     * @note Test Cases:\n
     * auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));\n
     * c1.set_fov(45); -> fov should be 45\n
     * c1.set_fov(0) -> ERROR: will throw a CameraException (0 is not in (0, 180))\n
     * c1.set_fov(180) -> ERROR: will throw a CameraException (180 is not in (0, 180))\n
     * c1.set_fov(-1) -> ERROR: will throw a CameraException (-1 is not in (0, 180))\n
     * c1.set_fov(181) -> ERROR: will throw a CameraException (181 is not in (0, 180))\n
     */
    void set_fov(float fov);
};

#endif //CAMERA_H
