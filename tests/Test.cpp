// Includes
#include "../lib/glm/glm/glm.hpp"
#include "../lib/glm/glm/vec3.hpp"
#include "../src/Renderer/RenderTarget.h"

using namespace glm;

// Camera
#include "../src/Camera/Camera.h"

// Materials
#include <cstdio>
#include <memory>
#include <cassert>

#include "../src/Materials/Dielectric.h"
#include "../src/Materials/Lambertian.h"
#include "../src/Materials/Metal.h"

// Macros

// Structures

// Prototypes
bool TestCamera();
bool TestDielectric();
bool TestLambertian();
bool TestMetal();

// Main Function
int main() {
    printf("Camera Test: ");
    assert(TestCamera());

    printf("Dielectric Test: ");
    assert(TestDielectric());

    printf("Lambertian Test: ");
    assert(TestLambertian());

    printf("Metal Test: ");
    assert(TestMetal());
}

// Camera
bool TestCamera() {
    try {
        int width = 1280;
        int height = 720;

        // Render target
        auto render_target = std::make_shared<RenderTarget>(width, height);

        // Camera
        auto camera = std::make_shared<Camera>(dvec3(4, -2, 0.5), dvec3(0, 0, 0));

        camera->set_focus_distance(4);
        camera->set_focus_angle(4);
        camera->set_vfov(45);

        assert(camera != nullptr);
        assert(camera->get_focus_distance() == 4);
        assert(camera->get_focus_angle() == 4);
        assert(camera->get_vfov() == 45);

        return true;
    }
    catch (const std::exception &e) {
        printf("Camera Test Failed: %s\n", e.what());
        return false;
    }
}

// Material
bool TestDielectric() {
    try {
        //index of refraction
        float refaction = 1.5;

        // Material
        auto material_dielectric = std::make_shared<Dielectric>(refaction);

        assert(material_dielectric != nullptr);
        assert(material_dielectric->get_index_of_refraction() == 1.5);

        return true;
    }
    catch (const std::exception &e) {
        printf("Dielectric Test Failed: %s\n", e.what());
        return false;
    }
}

bool TestLambertian() {
    try {
        dvec3 color(0.4, 0.2, 0.1);

        // Material
        auto material_lambertian = std::make_shared<Lambertian>(color);

        assert(material_lambertian != nullptr);
        assert(material_lambertian->get_color() == color);

        return true;
    }
    catch (const std::exception &e) {
        printf("Lambertian Test Failed: %s\n", e.what());
        return false;
    }
}

bool TestMetal() {
    try {
        // Color
        dvec3 color(0.7, 0.6, 0.5);

        // Roughness
        float roughness = 0.0;

        // Material
        auto material_metal = std::make_shared<Metal>(color, roughness);

        assert(material_metal != nullptr);
        assert(material_metal->get_color() == color);
        assert(material_metal->get_roughness() == roughness);

        return true;
    }
    catch (const std::exception &e) {
        printf("Metal Test Failed: %s\n", e.what());
        return false;
    }
}
