// Includes
#include "../src/Materials/Metal.h"

// Macros

// Structures

// Prototypes
bool TestMaterial();

// Main Function
int main() {
    // Test Functions
    TestMaterial();
}

// Camera
bool TestMaterial() {
    bool test = true;

    try {
        // Material
        auto material_metal = make_shared<Metal>(dvec3(0.85), 0.01);

        //Insert assertion statement here
    }
    catch (const std::exception& e) {
        test = false;
    }
    return test; // Return test results
}
