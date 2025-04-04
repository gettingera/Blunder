#ifndef COLOR_H
#define COLOR_H
#include <Utils/Headers.h>

/**
 * Defines color using an internal format.
 */
class Color {
    /// Vector containing the rgb values of the color. [0, 1]^3
    vec3 color{infinity, infinity, infinity};

public:
    // Constructors
    /**
     * Creates a new color.
     * @param color Vector containing color component information to be stored in a color.
     *
     * @notes Test Cases:\n
     * auto c1 = Color(vec3(0, 0, 0)) -> color should be (0, 0, 0)\n
     * auto c2 = Color(vec3(1, 1, 1)) -> color should be (1, 1, 1)\n
     * auto c3 = Color(vec3(2, 2, 2)) -> ERROR: will throw a ColorException (components outside [0, 1])\n
     * auto c4 = Color(vec3(-1, -1, -1)) -> ERROR: will throw a ColorException (components outside [0, 1])\n
     */
    explicit Color(const vec3 &color);

    /**
     * Creates a new color.
     * @param r Red value component in [0, 1]
     * @param g Green value component in [0, 1]
     * @param b Blue value component in [0, 1]
     *
     * @note Test Cases:\n
     * auto c1 = Color(0, 0, 0) -> color should be (0, 0, 0)\n
     * auto c2 = Color(1, 1, 1) -> color should be (1, 1, 1)\n
     * auto c3 = Color(2, 2, 2) -> ERROR: will throw a ColorException (components outside [0, 1])\n
     * auto c4 = Color(-1, -1, -1) -> ERROR: will throw a ColorException (components outside [0, 1])\n
     */
    Color(float r, float g, float b);

    // Getters
    /// Gets the vector containing color data.
    [[nodiscard]] vec3 get_color() const { return color; }

    // Setters
    /**
     * Sets the color data.
     * @param color Vector containing color data to be stored.
     *
     * @note Test Cases:\n
     * auto c1 = Color(vec3(0, 0, 0)) -> color should be (0, 0, 0)\n
     * c1.set_color(vec3(1, 1, 1)) -> color should be (1, 1, 1)\n
     * c1.set_color(vec3(2, 2, 2)) -> ERROR: will throw a ColorException (color components not inside bounds)\n
     * c1.set_color(vec3(-1, -1, -1)) -> ERROR: will throw a ColorException (color components not inside bounds)\n
     */
    void set_color(const vec3 &color);
};

#endif //COLOR_H
