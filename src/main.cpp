// Includes
#include "Utils/Headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/Sphere.h"
#include "Geometry/Triangle.h"
#include "Renderer/Raytracer.h"
#include "Materials/Material.h"
#include "Geometry/BVH_Node.h"


// Main method
int main() {
    // Camera dimensions
    int width = 1200/2;
    int height = 800/2;

    // Render target
    const auto render_target = make_shared<RenderTarget>(width, height);

    // Camera setup (z-up)
    const auto camera = make_shared<Camera>(dvec3(8, 3, 12), dvec3(0, 0, 0));
    camera->set_focus_distance(10.0);
    camera->set_focus_angle(0);
    camera->set_vfov(45);

    // World creation
    auto world = HittableList();

    // Ground plane
    auto ground_material = make_shared<Lambertian>(dvec3(0.5, 0.5, 0.5));
    world.Add(make_shared<Sphere>(dvec3(0, 0, -1000), 1000, ground_material));

    // Random spheres
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            dvec3 center(a + 0.9 * random_double(), b + 0.9 * random_double(), 0.2);

            if ((center - dvec3(4, 0, 0.2)).length() > 0.9) {
                shared_ptr<Material> sphere_material;

                if (choose_mat < 0.8) {
                    auto albedo = random_dvec3() * random_dvec3();
                    sphere_material = make_shared<Lambertian>(albedo);
                    world.Add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    auto albedo = random_dvec3(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<Metal>(albedo, fuzz);
                    world.Add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = make_shared<Dielectric>(1.5);
                    world.Add(make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    // Large spheres
    world.Add(make_shared<Sphere>(dvec3(0, 0, 3), 1.0, make_shared<Dielectric>(1.5)));
    world.Add(make_shared<Sphere>(dvec3(-4, 0, 1), 1.0, make_shared<Lambertian>(dvec3(0.4, 0.2, 0.1))));
    world.Add(make_shared<Sphere>(dvec3(4, 0, 1), 1.0, make_shared<Metal>(dvec3(0.7, 0.6, 0.5), 0.0)));

    // Box creation (centered at (0, 0, 0) with size 2)
    dvec3 v0(-1, -1, 0);  // bottom-left-front
    dvec3 v1( 1, -1, 0);  // bottom-right-front
    dvec3 v2( 1,  1, 0);  // top-right-front
    dvec3 v3(-1,  1, 0);  // top-left-front
    dvec3 v4(-1, -1,  2);  // bottom-left-back
    dvec3 v5( 1, -1,  2);  // bottom-right-back
    dvec3 v6( 1,  1,  2);  // top-right-back
    dvec3 v7(-1,  1,  2);  // top-left-back

    // Create box triangles (each face is 2 triangles)
    auto box_material1 = make_shared<Lambertian>(dvec3(0.8, 0.1, 0.1));  // Red material
    auto box_material2 = make_shared<Metal>(dvec3(0.7, 0.7, 0.7), 0.0);  // Silver material
    auto box_material3 = make_shared<Dielectric>(1.5);  // Dielectric material

    // Front face
    world.Add(make_shared<Triangle>(v0, v1, v2, box_material1));
    world.Add(make_shared<Triangle>(v0, v2, v3, box_material1));

    // Back face
    world.Add(make_shared<Triangle>(v4, v5, v6, box_material2));
    world.Add(make_shared<Triangle>(v4, v6, v7, box_material2));

    // Left face
    world.Add(make_shared<Triangle>(v0, v3, v7, box_material3));
    world.Add(make_shared<Triangle>(v0, v7, v4, box_material3));

    // Right face
    world.Add(make_shared<Triangle>(v1, v2, v6, box_material1));
    world.Add(make_shared<Triangle>(v1, v6, v5, box_material1));

    // Top face
    world.Add(make_shared<Triangle>(v2, v3, v7, box_material2));
    world.Add(make_shared<Triangle>(v2, v7, v6, box_material2));

    // Bottom face
    world.Add(make_shared<Triangle>(v0, v1, v5, box_material3));
    world.Add(make_shared<Triangle>(v0, v5, v4, box_material3));

    // BVH Instantiation
    auto new_world = make_shared<HittableList>();
    new_world->Add(make_shared<BVH_Node>(world));

    // Scene instantiation
    const Scene scene{new_world, camera};

    // Render to RTT
    Raytracer rt;
    rt.set_samples(10);
    rt.set_max_depth(50);
    rt.Render(scene, render_target);

    render_target->WriteToFile("output.ppm");
}
