#include "RenderTarget.h"
#include <fstream>

RenderTarget::RenderTarget(const int width, const int height) {
    // Set width and height
    set_width(width);
    set_height(height);

    // Initialize pixel grid
    initialize();
}

void RenderTarget::initialize() {
    // Create pixel grid full of black pixels
    colors = std::vector(get_height(), std::vector(get_width(), Color(0, 0, 0)));
}

Color RenderTarget::get_pixel(const int x, const int y) const {
    // Ensure x and y are within bounds
    if (x < 0 || y < 0 || x >= get_width() || y >= get_height())
        throw RenderTargetException("RenderTarget::get_pixel(): pixel index out of bounds");

    // Retrieve the color at the index
    return colors[y][x];
}

void RenderTarget::set_pixel(const int x, const int y, const Color &pixel) {
    // Ensure x and y are within bounds
    if (x < 0 || y < 0 || x >= get_width() || y >= get_height())
        throw RenderTargetException("RenderTarget::set_pixel(): pixel index out of bounds");

    // Set the color at the index
    colors[y][x] = pixel;
}

void RenderTarget::writeToFile(const std::string &filename) const {
    // Ensure the filename is not empty
    if (filename.empty())
        throw RenderTargetException("RenderTarget::WriteToFile(): empty filename");

    // Attempt to write to file, throw a RenderTargetException if any system errors occur
    try {
        std::ofstream file(filename + ".ppm");

        // PPM Header
        file << "P3\n" << get_width() << " " << get_height() << "\n255\n";

        // Generate PPM contents
        for (int y = 0; y < get_height(); y++) {
            for (int x = 0; x < get_width(); x++) {
                // Get pixel
                const auto pixel = get_pixel(x, y).get_color();

                // Gamma correction
                auto r = linear_to_gamma(pixel.r);
                auto g = linear_to_gamma(pixel.g);
                auto b = linear_to_gamma(pixel.b);

                // Write integer converted color data to file
                file <<
                        static_cast<int>(255.999 * r) << " " <<
                        static_cast<int>(255.999 * g) << " " <<
                        static_cast<int>(255.999 * b) << "\n";
            }
        }

        // Close file
        file.close();
    } catch (const std::exception &e) {
        throw RenderTargetException(
            "RenderTarget::WriteToFile(): system error writing to file: " + std::string(e.what()));
    }
}

void RenderTarget::set_width(const int width) {
    // Ensure width is above zero
    if (width <= 0)
        throw RenderTargetException("RenderTarget::set_width(): width must be greater than 0");

    // Ensure width is below vector size limit
    if (width > colors.max_size())
        throw RenderTargetException("RenderTarget::set_width(): width exceeds maximum size");

    // Set width
    this->width = width;

    // Reinitialize colors
    initialize();
}

void RenderTarget::set_height(const int height) {
    // Ensure height is above zero
    if (height <= 0)
        throw RenderTargetException("RenderTarget::set_height(): height must be greater than 0");

    // Ensure height is below vector size limit
    if (height > colors[0].max_size())
        throw RenderTargetException("RenderTarget::set_height(): height exceeds maximum size");

    // Set height
    this->height = height;

    // Reinitialize colors
    initialize();
}
