#ifndef RENDERTARGET_H
#define RENDERTARGET_H
#include <Utils/Headers.h>

/**
 * Render target representing an image in memory.
 * The primary purpose of a render target is to keep an image in memory until it is ready for other operations.
 * It also gives the renderer something to render to.
 */
class RenderTarget {
    /// Width in pixels of the image.
    int width{1};

    /// Height in pixels of the image.
    int height{1};

    /// Two dimensional array of pixels.
    std::vector<std::vector<Color>> colors;

public:
    // Constructors
    /**
     * Makes a new render target.
     * @param width Width, in pixels.
     * @param height Height, in pixels.
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(100, 100) -> width should be 100, height should be 100
     * auto rt2 = RenderTarget(0, 0) -> ERROR: will throw a RenderTargetException
     * auto rt3 = RenderTarget(-1, -1) -> ERROR: will throw a RenderTargetException
     */
    RenderTarget(int width, int height);

    // Methods
    /**
     * Initializes the render target with black pixels.
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(100, 100) -> any valid get_pixel_color call should return Color.get_color() -> (0, 0, 0)
     * rt1.initialize() -> any valid get_pixel_color call should return Color.get_color() -> (0, 0, 0)
     */
    void initialize();

    /**
     * Gets the color located at (x, y).
     * @param x x pixel coordinate.
     * @param y y pixel coordinate.
     * @return Color of pixel (x, y).
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(101, 101)
     * rt1.get_pixel(0, 0) -> color of the top left pixel.
     * rt1.get_pixel(50, 50) -> color of the center pixel.
     * rt1.get_pixel(100, 100) -> color of the bottom right pixel.
     * rt1.get_pixel(-1, -1) -> ERROR: will throw a RenderTargetException (pixel out of bounds)
     * rt1.get_pixel(101, 101) -> ERROR: will throw a RenderTargetException (pixel out of bounds)
     */
    [[nodiscard]] Color get_pixel(int x, int y) const;

    /**
     * Sets the color located at (x, y).
     * @param x x pixel coordinate.
     * @param y y pixel coordinate.
     * @param pixel Color of pixel to be at (x, y).
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(101, 101)
     * auto white = Color(1, 1, 1)
     * rt1.set_pixel(0, 0, white) -> color of the top left pixel should be (1, 1, 1)
     * rt1.set_pixel(50, 50, white) -> color of the center pixel should be (1, 1, 1)
     * rt1.set_pixel(100, 100, white) -> color of the bottom right pixel should be (1, 1, 1)
     * rt1.set_pixel(-1, -1, white) -> ERROR: will throw a RenderTargetException (pixel out of bounds)
     * rt1.set_pixel(101, 101, white) -> ERROR: will throw a RenderTargetException (pixel out of bounds)
     */
    void set_pixel(int x, int y, const Color &pixel);

    /**
     * Writes the render target to an output file.
     * @param filename Name of the file to export to.
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(100, 100)
     * rt1.writeToFile("cool") -> should generate a file cool.ppm in bin/
     * rt1.writeToFile("") -> ERROR: will throw a RenderTargetException (filename must be provided)
     * rt1.writeToFile("cool") fails for some other reason -> ERROR: will throw a RenderTargetException (some system error occurred)
     */
    void writeToFile(const std::string &filename) const;

    // Getters
    /// Gets the width in pixels of the render target.
    [[nodiscard]] int get_width() const { return width; }

    /// Gets the height in pixels of the render target.
    [[nodiscard]] int get_height() const { return height; }

    // Setters
    /**
     * Sets the width of the render target.
     * @param width Width in pixels.
     *
     * @note Test Cases:
     * auto rt1 = RenderTarget(100, 100)
     * rt1.set_width(1000) -> width should be 1000
     * rt1.set_width(1) -> width should be 1
     * rt1.set_width(0) -> ERROR: will throw a RenderTargetException (width must be greater than zero)
     * rt1.set_width(-1) -> ERROR: will throw a RenderTargetException (width must be greater than zero)
     */
    void set_width(int width);

    /**
     * Sets the height of the render target.
     * @param height Height in pixels.
     *
    * @note Test Cases:
     * auto rt1 = RenderTarget(100, 100)
     * rt1.set_height(1000) -> height should be 1000
     * rt1.set_height(1) -> height should be 1
     * rt1.set_height(0) -> ERROR: will throw a RenderTargetException (height must be greater than zero)
     * rt1.set_height(-1) -> ERROR: will throw a RenderTargetException (height must be greater than zero)
     */
    void set_height(int height);
};

#endif //RENDERTARGET_H
