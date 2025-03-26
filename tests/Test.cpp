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

//Camera
void TestCameraPass(void);
void TestCameraFail(void);

//Geometry
void TestGeometryPass(void);
void TestGeometryFail(void);

//Materials
void TestMaterialsPass(void);
void TestMaterialsFail(void);

//Renderer
void TestRendererPass(void);
void TestRendererFail(void);

//Scene
void TestScenePass(void);
void TestSceneFail(void);

//Utils
void TestUtilsPass(void);
void TestUtilsFail(void);

// main Function
int main() {
    // Test Camera
    TestCameraPass();
    TestCameraFail();

    // Test Geometry
    TestGeometryPass();
    TestGeometryFail();

    // Test Materials
    TestMaterialsPass();
    TestMaterialFail();

    // Test Renderer
    TestRendererPass();
    TestRendererFail();

    // Test Scene
    TestScenePass();
    TestSceneFail();

    // Test Utils
    TestUtilsPass();
    TestUtilsFail();
}

void TestCameraPass() {
    int width = 1280/2;
    int height = 720/2;
    RenderTarget(width, height);
}

void TestCameraFail() {
    float32 width = 5.0f;
    float32 height = 6.0f;
    RenderTarget(width, height);

}

void TestGeometryPass() {

}

void TestGeometryFail() {

}

void TestMaterialsPass() {

}

void TestMaterialFail() {

}

void TestRendererPass() {

}

void TestRendererFail() {

}

void TestScenePass() {

}

void TestSceneFail() {

}

void TestUtilsPass() {

}

void TestUtilsFail() {

}