// Includes

// Camera
#include <cstdio>
#include "Camera/Camera.h"
#include <glm/glm.hpp>

// Materials

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
    TestCamera();
    printf("Test Passed");

    /*
    printf("Dielectric Test: ");
    assert(TestDielectric());
    printf("Test Passed");

    printf("Lambertian Test: ");
    assert(TestLambertian());
    printf("Test Passed");

    printf("Metal Test: ");
    assert(TestMetal());
    printf("Test Passed");
    */
}

// Camera
bool TestCamera() {
    int width = 1920 / 2;
    int height = 1080 / 2;
    return true;

}
/*

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
*/