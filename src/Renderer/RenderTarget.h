#ifndef RENDERTARGET_H
#define RENDERTARGET_H
#include <vector>
#include <fstream>


/**
 * Render target representing an image in memory.
 *
 * Useful for rendering scenes directly to an image in memory and offering conversions and export functionality.
 */
class RenderTarget {
    /// Width in pixels of the image.
    int width{};

    /// Height in pixels of the image.
    int height{};

    /// Two dimensional array of pixels.
    std::vector<std::vector<dvec3> > pixels;
public:
    // Constructors
    /**
     * Makes a new render target.
     *
     * @param width Width, in pixels.
     * @param height Height, in pixels.
     */
    RenderTarget(const int width, const int height) {
        set_width(width);
        set_height(height);

        Initialize();
    }

    // Methods
    /**
     * Initializes the render target with black pixels.
     */
    void Initialize() {
        pixels = std::vector(height, std::vector<dvec3>(width, dvec3(0)));
    }

    /**
     * Writes the render target to an output file.
     *
     * @param filename Name of the file to export to.
     */
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
    /**
     * Gets the color of the pixel (x, y).
     *
     * @param x x coordinate of pixel.
     * @param y y coordinate of pixel.
     * @return Color of pixel.
     */
    [[nodiscard]] dvec3 GetPixel(const int x, const int y) const {
        return pixels[y][x];
    }

    /**
     * Sets the color of the pixel (x, y).
     *
     * @param x x coordinate of pixel.
     * @param y y coordinate of pixel.
     * @param pixel Color of pixel.
     */
    void SetPixel(const int x, const int y, const dvec3 &pixel) {
        pixels[y][x] = pixel;
    }

    // Getters
    /**
     * Gets width.
     *
     * @return Width.
     */
    [[nodiscard]] int get_width() const {
        return width;
    }

    /**
     * Gets height.
     *
     * @return Height.
     */
    [[nodiscard]] int get_height() const {
        return height;
    }

    // Setters
    /**
     * Sets width.
     *
     * @param width Width.
     */
    void set_width(const int width) {
        this->width = width;
    }

    /**
     * Sets height.
     *
     * @param height Height.
     */
    void set_height(const int height) {
        this->height = height;
    }
};


#endif //RENDERTARGET_H
