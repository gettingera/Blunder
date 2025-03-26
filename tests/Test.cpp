//Includes

//Camera
#include "Camera/Camera.h"

//Geometry
#include "Geometry/HitRecord.h"
#include "Geometry/Hittable.h"
#include "Geometry/HittableList.h"
#include "Geometry/Sphere.h"

//Materials
#include "Materials/Dielectric.h"
#include "Materials/Lambertian.h"
#include "Materials/Material.h"
#include "Materials/Metal.h"

//Renderer
#include "Renderer/Raytracer.h"
#include "Renderer/Renderer.h"
#include "Renderer/RenderTarget.h"

//Scene
#include "Scene/Scene.h"

//Utils
#include "Utils/Headers.h"
#include "Utils/Interval.h"
#include "Utils/Ray.h"

//Main
#include "main.cpp"

//Macros

//Prototypes
void TestCamera(void);
void TestGeometry(void);
void TestMaterials(void);
void TestRenderer(void);
void TestScene(void);
void TestUtils(void);

// main Function
int main() {
    // Test Camera
    TestCamera();

    // Test Geometry
    TestGeometry();

    // Test Materials
    TestMaterials();

    // Test Renderer
    TestRenderer();

    // Test Scene
    TestScene();

    // Test Utils
    TestUtils();
}

void TestCamera() {
    int width = 1280/2;
    int height = 720/2;
    RenderTarget(width, height);
}

void TestGeometry() {

}

void TestMaterials() {

}

void TestRenderer() {

}

void TestScene() {

}

void TestUtils() {

}