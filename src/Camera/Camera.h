#ifndef CAMERA_H
#define CAMERA_H


/**
 * A camera for viewing and rendering 3D scenes.
 *
 * This positionable camera provides utilities for safe storage and manipulation of the camera.
 */
class Camera {
    /// World position of camera.
    dvec3 position{};

    /// Position in world where camera will be pointed.
    dvec3 direction{};

    /// Vector indicating what direction should be considered upward.
    dvec3 up_direction = dvec3(0, 0, 1);

    /// Vertical FOV for zooming the camera in and out.
    double vfov = 90;

    /// The distance from the camera position that the scene will be in perfect focus.
    double focus_distance = 0;

    /// The amount of blur. (depth of field)
    double focus_angle = 0;

public:
    // Constructors
    /**
     * Initializes the camera for the 3D scene.
     *
     * @param position World position of camera.
     * @param direction Position in world where camera will be pointed.
     */
    Camera(const dvec3 &position, const dvec3 &direction) {
        set_position(position);
        set_direction(direction);
    }

    // Getters
    /**
     * Gets position.
     * 
     * @return World position of camera.
     */
    [[nodiscard]] dvec3 get_position() const {
        return position;
    }

    /**
     * Gets direction.
     * 
     * @return Position in world where camera will be pointed.
     */
    [[nodiscard]] dvec3 get_direction() const {
        return direction;
    }

    /**
     * Gets up_direction.
     * 
     * @return Vector indicating what direction should be considered upward.
     */
    [[nodiscard]] dvec3 get_up_direction() const {
        return up_direction;
    }

    /**
     * Gets vfov.
     * 
     * @return Vertical FOV for zooming the camera in and out.
     */
    [[nodiscard]] double get_vfov() const {
        return vfov;
    }

    /**
     * Gets focus_distance.
     * 
     * @return The distance from the camera position that the scene will be in perfect focus.
     */
    [[nodiscard]] double get_focus_distance() const {
        return focus_distance;
    }

    /**
     * Gets focus_angle.
     * 
     * @return The amount of blur. (depth of field)
     */
    [[nodiscard]] double get_focus_angle() const {
        return focus_angle;
    }

    // Setters
    /**
     * Sets position.
     * 
     * @param position World position of camera.
     */
    void set_position(const dvec3 &position) {
        this->position = position;
    }

    /**
     * Sets direction.
     * 
     * @param direction Position in world where camera will be pointed.
     */
    void set_direction(const dvec3 &direction) {
        this->direction = direction;
    }

    /**
     * Sets up_direction.
     * 
     * @param up_direction Vector indicating what direction should be considered upward.
     */
    void set_up_direction(const dvec3 &up_direction) {
        this->up_direction = up_direction;
    }

    /**
     * Sets vfov.
     * 
     * @param vfov Vertical FOV for zooming the camera in and out.
     */
    void set_vfov(const double vfov) {
        this->vfov = vfov;
    }

    /**
     * Sets focus_distance.
     * 
     * @param focus_distance The distance from the camera position that the scene will be in perfect focus.
     */
    void set_focus_distance(const double focus_distance) {
        this->focus_distance = focus_distance;
    }

    /**
     * Sets focus_angle.
     * 
     * @param focus_angle The amount of blur. (depth of field)
     */
    void set_focus_angle(const double focus_angle) {
        this->focus_angle = focus_angle;
    }
};


#endif //CAMERA_H
