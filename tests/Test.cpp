// Includes
#include <memory>

#include "../src/Camera/Camera.h"
#include "../src/Materials/Metal.h"
#include "../src/Renderer/RenderTarget.h"
#include "../src/Scene/Scene.h"
#include "../src/Geometry/Sphere.h"

// Macros

// Structures

// Prototypes
bool TestMaterial();
bool TestCamera();

// Main Function
int main() {
    // Test Functions
    TestMaterial();
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
bool TestMaterial() {
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
