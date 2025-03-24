// Includes
#include <cstdio>
#include <glm/glm.hpp>
#include "Renderer/RenderTarget.h"

// Macros

// Prototypes

// Main method
int main() {
    const auto rtt1 = new RenderTarget(100, 100);
    rtt1->SetPixel(0, 0, glm::vec3(255));
    auto p1 = rtt1->GetPixel(101, 0);
    printf("(%f, %f, %f)\n", p1.x, p1.y, p1.z);
    rtt1->WriteToFile("woah.ppm");
}

// Implementations
