// Includes
#include "Utils/Headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/Sphere.h"
#include "Renderer/Raytracer.h"

// Macros

// Prototypes

// Main method
int main() {
    // Camera dimensions
    int width = 1280/2;
    int height = 720/2;

    // Render target
    const auto render_target = make_shared<RenderTarget>(width, height);

    // Camera
    const auto camera = make_shared<Camera>(dvec3(1, 10, 1), dvec3(0, 0, 0.5), dvec3(0, 0, 1));

    // World creation
    const auto world = make_shared<HittableList>();

    // Object instances
    world->Add(make_shared<Sphere>(dvec3(0, 0, 0.5), 1));
    world->Add(make_shared<Sphere>(dvec3(0, 0, -100.5), 100));

    // Scene instantiation
    const Scene scene{world, camera};

    // Render to RTT
    Raytracer rt;
    rt.Render(scene, render_target);

    render_target->WriteToFile("output.ppm");
}

// Implementations
