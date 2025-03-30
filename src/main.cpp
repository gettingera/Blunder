// Includes
#include "Utils/Headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/Sphere.h"
#include "Geometry/Triangle.h"
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
    const auto camera = make_shared<Camera>(dvec3(10, -3, 0.5), dvec3(0, 0, 0));
    camera->set_focus_distance(4);
    camera->set_focus_angle(0);
    camera->set_vfov(45);

    // World creation
    const auto world = make_shared<HittableList>();

    // Materials!
    auto material_green = make_shared<Lambertian>(dvec3(0.8, 0.8, 0.05));
    auto material_red = make_shared<Lambertian>(dvec3(0.8, 0, 0.05));
    auto material_metal = make_shared<Metal>(dvec3(0.85), 0.1);
    auto material_glass = make_shared<Dielectric>(1.5);
    auto material_bubble = make_shared<Dielectric>(1.0/1.5);

    // Object instances
    world->Add(make_shared<Sphere>(dvec3(0, 0, -101), 100, material_green));
    world->Add(make_shared<Sphere>(dvec3(0, 0, 0), dvec3(0, -1, 0), 1, material_red));
    // world->Add(make_shared<Sphere>(dvec3(-2, 0, 0.5), 1, material_glass));
    // world->Add(make_shared<Sphere>(dvec3(-2, 0, 0.5), 0.8, material_bubble));
    // world->Add(make_shared<Sphere>(dvec3(2, 0, 0.5), 1, material_metal));

    auto triangle = make_shared<Triangle>(
        Ray(dvec3(-5, 1, -2), dvec3(-5, 1, -2)),
        Ray(dvec3(0, 1, 5), dvec3(0, 0, 5)),
        Ray(dvec3(5, 1, -2), dvec3(5, 1, -2)),
        material_metal);

    triangle->InvertNormals();

    world->Add(triangle);

    // Scene instantiation
    const Scene scene{world, camera};

    // Render to RTT
    Raytracer rt;
    rt.set_samples(10);
    rt.set_max_depth(10);

    rt.Render(scene, render_target);

    render_target->WriteToFile("output.ppm");
}

// Implementations
