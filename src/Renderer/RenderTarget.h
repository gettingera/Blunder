#ifndef RENDERTARGET_H
#define RENDERTARGET_H


#include <vector>
#include <fstream>


class RenderTarget {
public:
    // Constructor
    RenderTarget(const int width, const int height) {
        set_width(width);
        set_height(height);

        Initialize();
    }

    // Methods
    void Initialize() {
        pixels = std::vector(height, std::vector<glm::dvec3>(width, glm::dvec3(0)));
    }

    void WriteToFile(const std::string &filename) const {
        std::ofstream file(filename);

        // Interval for intensity, valid mapping of colors
        static const Interval intensity(0, 0.999);

        // PPM Header
        file << "P3\n" << width << " " << height << "\n255\n";

        // Generate PPM contents
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Get pixel
                const auto pixel = GetPixel(x, y);

                // Gamma correction
                auto r = linear_to_gamma(pixel.x);
                auto g = linear_to_gamma(pixel.y);
                auto b = linear_to_gamma(pixel.z);

                // Write integer converted color data to file
                file <<
                        static_cast<int>(256 * intensity.clamp(r)) << " " <<
                        static_cast<int>(256 * intensity.clamp(g)) << " " <<
                        static_cast<int>(256 * intensity.clamp(b)) << "\n";
            }
        }

        // Close file
        file.close();
    }

    // Accessors
    [[nodiscard]] glm::dvec3 GetPixel(const int x, const int y) const {
        return pixels[y][x];
    }

    void SetPixel(const int x, const int y, const glm::dvec3 &pixel) {
        pixels[y][x] = pixel;
    }

    // Getters
    [[nodiscard]] int get_width() const {
        return width;
    }

    [[nodiscard]] int get_height() const {
        return height;
    }

    // Setters
    void set_width(const int width) {
        this->width = width;
    }

    void set_height(const int height) {
        this->height = height;
    }

private:
    // Attributes
    int width{}, height{};
    std::vector<std::vector<glm::dvec3> > pixels;
};


#endif //RENDERTARGET_H
