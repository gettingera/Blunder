// Includes

// Camera
#include "../src/Camera/Camera.h"

// Materials
#include <cstdio>

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
    TestCamera();
    TestDielectric();
    TestLambertian();
    TestMaterial();
    TestMetal();
}

// Camera
bool TestCamera() {
    bool test = true;
    try {
        int width = 1280;
        int height = 720;

        // Render target
        const auto render_target = make_shared<RenderTarget>(width, height);

        // Camera
        const auto camera = make_shared<Camera>(dvec3(4, -2, 0.5), dvec3(0, 0, 0));

        camera->set_focus_distance(4);
        camera->set_focus_angle(4);
        camera->set_vfov(45);

        //Insert assertion statement here
    }
    catch (const std::assertion_error& e) {
        test = false;
    }
    return test;
}

// Material

bool TestDielectric() {
    bool test = true;

    try {
        // Material
        auto material_Dielectric = std::make_shared<Dielectric>(dvec3(0.85), 0.01);

        //Insert assertion statement here
    }
    catch (const std::assertion_error& e) {
        test = false;
    }
    return test; // Return test results
}


bool TestLambertian() {
    bool test = true;

    try {
        // Material
        auto material_lambertian = std::make_shared<Lambertian>(dvec3(0.85), 0.01);

        //Insert assertion statement here
    }
    catch (const std::assertion_error& e) {
        test = false;
    }
    return test; // Return test results
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
