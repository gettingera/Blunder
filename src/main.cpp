// Includes
#include <Camera/Camera.h>
#include <Utils/Color.h>
#include <Renderer/RenderTarget.h>
#include <Geometry/Sphere.h>
#include "Geometry/SphereList.h"
#include "Renderer/Renderer.h"

// Main method
int main() {
    const auto c1 = make_shared<Camera>(vec3(3, -1, -1), vec3(0, 0, 0));
    c1->set_fov(45);
    const auto rt1 = make_shared<RenderTarget>(800, 400);
    auto red = Color(1.0, 0.2, 0.2);
    auto white = Color(1.0, 1.0, 1.0);
    auto blue = Color(0.2, 0.2, 0.8);

    const auto s1 = make_shared<Sphere>(vec3(-2, 0, 0), 1.0, red);
    const auto s2 = make_shared<Sphere>(vec3(0, 0, 0), 1.0, white);
    const auto s4 = make_shared<Sphere>(vec3(-1, 0, 1.14), 0.5, blue);
    const auto s5 = make_shared<Sphere>(vec3(1, 0, 1.14), 0.5, red);
    const auto s3 = make_shared<Sphere>(vec3(2, 0, 0), 1.0, blue);

    const auto spheres = make_shared<SphereList>();
    spheres->Add(s1);
    spheres->Add(s2);
    spheres->Add(s3);
    spheres->Add(s4);
    spheres->Add(s5);

    Renderer raytracer(100, 10);
    raytracer.render(spheres, c1, rt1);

    rt1->writeToFile("render");

    return 0;
}
