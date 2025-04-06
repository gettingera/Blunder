#ifndef RENDERER_H
#define RENDERER_H
#include <Utils/Headers.h>

#include "RenderTarget.h"
#include "Camera/Camera.h"
#include "Geometry/SphereList.h"

/**
 * Utility structure to hold necessary camera values and computations for ray tracing.
 * It caches and saves large amounts of arguments that would have to be manually passed to functions otherwise.
 */
struct RT_CAMERA_VALUES {
    /// Length of camera origin to the 'lens' of the camera (direction)
    float focal_length;

    /// FOV of the viewing camera, in radians
    float theta;

    /// Triangle vertical component (camera geometry processing)
    float h;

    /// World unit height of the viewport.
    float viewport_height;

    /// World unit width of the viewport.
    float viewport_width;

    /// Position of the viewing camera.
    vec3 position;

    /// Direction or 'lens' of the viewing camera.
    vec3 direction;

    /// Direction the camera considers to be upward.
    vec3 up_direction;

    /// First orthonormal basis vector of the camera.
    vec3 u;

    /// Second orthonormal basis vector of the camera.
    vec3 v;

    /// Third orthonormal basis vector of the camera.
    vec3 w;

    /// Vector spanning the width of the viewport.
    vec3 viewport_u;

    /// Vector spanning the height of the viewport.
    vec3 viewport_v;

    /// Vector spanning the width of a single pixel of the viewport.
    vec3 pixel_delta_u;

    /// Vector spanning the height of a single pixel of the viewport.
    vec3 pixel_delta_v;

    /// Location of the upper left point of the viewport in world space.
    vec3 viewport_upper_left;

    /// Location of the center of the upper left pixel in world space.
    vec3 pixel_upper_left;
};

class Renderer {
    /// Number of rays cast per pixel. Increases image quality.
    int samples = 10;

    /// Maximum number of times a ray is allowed to bounce before being terminated.
    int max_depth = 10;

public:
    // Constructors
    /**
     * Creates a new renderer.
     * @param samples Number of rays traced for each pixel.
     * @param max_depth Number of bounces each ray can have before termination.
     *
     * @note Test Cases:\n
     * Uses setter test cases.
     */
    Renderer(int samples, int max_depth);

    // Methods
    /**
     * Renders spheres through the perspective of a camera into a render target.
     * @param spheres Pointer to a SphereList containing the spheres to be rendered.
     * @param camera Pointer to a camera viewing the spheres to be rendered.
     * @param render_target Pointer to the image the function will output the rendered image to.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * ...\n
     * r1.Render(spheres, camera, render_target) -> should output an image to RenderTarget\n
     * ERROR: will throw a RendererException (will be thrown if any of the above arguments are nullptr)\n
     */
    void render(const shared_ptr<SphereList> &spheres, const shared_ptr<Camera> &camera, const shared_ptr<RenderTarget> &render_target) const;

    // Helpers
    /**
     * Initializes the camera values required for ray tracing.
     * @param camera Camera viewing the world.
     * @param render_target Render target that the output should be drawn to.
     * @return Struct containing all information necessary for ray tracing.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * ...\n
     * r1.initializeRTCamera(camera, render_target) -> should return an RT_CAMERA_VALUES struct containing values.\n
     * ERROR: will throw a RendererException (thrown if camera, render_target are nullptr)\n
     */
    static RT_CAMERA_VALUES initializeRTCamera(const shared_ptr<Camera> &camera, const shared_ptr<RenderTarget> &render_target);

    /**
     *
     * @param i Pixel along the width of the camera.
     * @param j Pixel along the height of the camera.
     * @param rt_camera_values Initialized RT_CAMERA_VALUES struct.
     * @return Ray from the position through the (i, j) pixel
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * ...\n
     * r1.getRayAtPixel(5, 5) -> gets a ray passing through the pixel (5, 5)\n
     * r1.getRayAtPixel(-1, -1) -> ERROR: will return a RendererException((i, j) pixel index is negative)\n
     */
    static Ray getRayAtPixel(int i, int j, const RT_CAMERA_VALUES &rt_camera_values);

    /**
     * Calculates the color of light passing through the scene over a particular ray.
     * @param ray Ray passing through the scene from the camera.
     * @param spheres Pointer to list of spheres to be rendered.
     * @return Vector holding the color of the ray after it has interacted with the spheres.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * ...\n
     * r1.getRayColor(ray, spheres) -> should return a Color containing the values after light interacted with the scene.\n
     * r1.getRayColor(ray, spheres) -> ERROR: will return a RendererException (if spheres is nullptr)\n
     */
    [[nodiscard]] Color getRayColor(Ray ray, const shared_ptr<SphereList> &spheres) const;

    /**
     * Gets the color of the sky at a particular direction of a ray.
     * @param ray Some ray.
     * @return Color of the sky depending on the direction of the ray.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * r1.getSkyColor(Ray(vec3(0, 0, 0), vec3(1, 1, 1))) -> will return a Color corresponding to the color of the sky.\n
     * NO EXCEPTIONS\n
     */
    static Color getSkyColor(const Ray &ray);

    /**
     * Scatters a ray of light to simulate material effects.
     * @param hit_record Information about the ray hitting an object.
     * @param scattered_ray Reference to a ray being scattered by the function.
     * @return True if the ray scatters (and sets scattered_ray), false if it doesn't (and leaves scattered_ray alone)
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * ...\n
     * r1.scatter(ray, hit_record, scattered_ray) -> returns true, modifies scattered_ray (no need to test)\n
     * r1.scatter(ray, hit_record, scattered_ray) -> returns false, doesn't modify scattered_ray (no need to test)\n
     *
     */
    static bool scatter(const HitRecord &hit_record, Ray &scattered_ray);

    // Getters
    /// Gets the number of rays drawn and averaged per pixel.
    [[nodiscard]] int get_samples() const {
        return samples;
    }

    /// Gets the maximum number of ray bounces in a scene before the ray is terminated.
    [[nodiscard]] int get_max_depth() const {
        return max_depth;
    }

    // Setters
    /**
     * Sets the number of rays drawn and averaged per pixel.
     * @param samples Number of rays.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * r1.set_samples(20) -> samples should be 20\n
     * r1.set_samples(1) -> samples should be 1\n
     * r1.set_samples(0) -> ERROR: will throw a RendererException (samples should be greater than zero)\n
     * r1.set_samples(-1) -> ERROR: will throw a RendererException (see above)\n
     */
    void set_samples(int samples);

    /**
     * Sets the maximum number of ray bounces in a scene before the ray is terminated.
     * @param max_depth Number of bounces.
     *
     * @note Test Cases:\n
     * auto r1 = Renderer(10, 10)\n
     * r1.set_max_depth(20) -> max_depth should be 20\n
     * r1.set_max_depth(1) -> max_depth should be 1\n
     * r1.set_max_depth(0) -> ERROR: will throw a RendererException (max_depth should be greater than zero)\n
     * r1.set_max_depth(-1) -> ERROR: will throw a RendererException (see above)\n
     */
    void set_max_depth(int max_depth);
};

#endif //RENDERER_H
