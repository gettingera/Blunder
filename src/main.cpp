// Includes
#define GLM_ENABLE_EXPERIMENTAL

#include "Utils/Headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/Sphere.h"
#include "Renderer/Raytracer.h"

// Macros

// Prototypes

// Main method
int main() {
    int width = 1280;
    int height = 720;

    auto render_target = make_shared<RenderTarget>(width, height);
    render_target->SetPixel(1, 1, glm::dvec3(1.0, 1.0, 1.0));

    render_target->WriteToFile("output.ppm");
}

// Implementations
