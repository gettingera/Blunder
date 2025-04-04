#include "Color.h"

Color::Color(const vec3 &color) {
    set_color(color);
}

Color::Color(const float r, const float g, const float b) {
    set_color(vec3(r, g, b));
}

void Color::set_color(const vec3 &color) {
    // Ensure color components are finite
    if (!is_finite(color))
        throw ColorException("Color::set_color(): color components should all be finite");

    // Ensure color components are within [0, 1]
    if (!is_inside_closed_range(color, 0, 1)) {
        throw ColorException("Color::set_color(): all color components should be inside [0, 1]");
    }

    // Set color
    this->color = color;
}
