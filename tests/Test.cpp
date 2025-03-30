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
#include <stdexcept>

#include "../src/Materials/Dielectric.h"
#include "../src/Materials/Lambertian.h"
#include "../src/Materials/Material.h"
#include "../src/Materials/Metal.h"

// Macros

// Structures

// Prototypes
bool TestCamera();
bool TestDielectric();
bool TestLambertian();
bool TestMaterial();
bool TestMetal();

// Main Function
int main() {
    // Test Functions
    assert(TestCamera());
    assert(TestDielectric());
    assert(TestLambertian());
    assert(TestMaterial());
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
        // Material
        auto material_dielectric = std::make_shared<Dielectric>(dvec3(0.85), 0.01);

        assert(material_dielectric != nullptr);
        assert(material_dielectric->get_reflectivity() == 0.01);

        return true;
    }
    catch (const std::exception &e) {
        printf("Dielectric Test Failed: %s\n", e.what());
        return false;
    }
}


bool TestLambertian() {
    try {
        // Material
        auto material_lambertian = std::make_shared<Dielectric>(dvec3(0.85), 0.01);

        assert(material_lambertian != nullptr);
        assert(material_lambertian->get_reflectivity() == 0.01);

        return true;
    }
    catch (const std::exception &e) {
        printf("Lambertian Test Failed: %s\n", e.what());
        return false;
    }
}


bool TestMaterial() {
    bool test = true;

    try {
        // Material
        auto material = std::make_shared<Material>(dvec3(0.85), 0.01);

        //Insert assertion statement here
    }
    catch (const std::assertion_error& e) {
        test = false;
    }
    return test; // Return test results
}

bool TestMetal() {
    bool test = true;

    try {
        // Material
        auto material_metal = std::make_shared<Metal>(dvec3(0.85), 0.01);

        //Insert assertion statement here
    }
    catch (const std::assertion_error& e) {
        test = false;
    }
    return test; // Return test results
}
