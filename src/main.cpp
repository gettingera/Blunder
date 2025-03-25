// Includes
#include "Utils/Headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/Sphere.h"
#include "Renderer/Raytracer.h"
#include "Materials/Material.h"

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
    const auto camera = make_shared<Camera>(dvec3(-4, 10, 3), dvec3(0, 0, 0.5), dvec3(0, 0, 1));

    // World creation
    const auto world = make_shared<HittableList>();

    // Materials!
    auto material_green = make_shared<Lambertian>(dvec3(0.8, 0.8, 0.0));
    auto material_metal = make_shared<Metal>(dvec3(0.85), 0.01);
    auto material_glass = make_shared<Dielectric>(1.5);
    auto material_bubble = make_shared<Dielectric>(1.0/1.5);

    // Object instances
    world->Add(make_shared<Sphere>(dvec3(0, 0, -100.5), 100, material_green));
    world->Add(make_shared<Sphere>(dvec3(0, 0, 0.5), 1, material_metal));
    world->Add(make_shared<Sphere>(dvec3(-2, 0, 0.5), 1, material_glass));
    world->Add(make_shared<Sphere>(dvec3(-2, 0, 0.5), 0.8, material_bubble));
    world->Add(make_shared<Sphere>(dvec3(2, 0, 0.5), 1, material_metal));

    // Scene instantiation
    const Scene scene{world, camera};

    // Render to RTT
    Raytracer rt;
    rt.Render(scene, render_target);

    render_target->WriteToFile("output.ppm");
}

// Implementations
