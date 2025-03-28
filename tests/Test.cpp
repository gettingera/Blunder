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
void TestCamera(void);

//Geometry
void TestGeometrySphere(void);

//Materials
void TestMaterialsDielectricPass(void);
void TestMaterialsDielectricFail(void);

void TestMaterialsLambertianPass(void);
void TestMaterialsLabertianFail(void);

void TestMaterialsMaterialPass(void);
void TestMaterialsMaterialFail(void);

void TestMaterialMetalPass(void);
void TestMaterialMetalFail(void);

//Renderer
void TestRendererRaytracer(void);
void TestRendererRenderer(void);
void TestRendererRenderTarget(void);


//Scene
void TestScenePass(void);
void TestSceneFail(void);

//Utils
void TestUtilsHeaders(void);


// main Function
int main() {
    // Test Camera
    TestCamera();

    // Test Geometry
    TestGeometrySphere();
    
    // Test Materials
    TestMaterialsDielectricPass();
    TestMaterialsDielectricFail();

    TestMaterialsLambertianPass();
    TestMaterialsLabertianFail();

    TestMaterialsMaterialPass();
    TestMaterialsMaterialFail();

    TestMaterialMetalPass();
    TestMaterialMetalFail();

    // Test Renderer
    TestRendererRaytracer();

    TestRendererRenderer();

    TestRendererRenderTarget();

    // Test Scene
    TestScene();

    // Test Utils
    TestUtilsHeaders();
}

//Camera
void TestCamera() {
    int width = 1280/2;
    int height = 720/2;
    if (RenderTarget(width, height)) {
        printf(true);
    } else {
        prinf(false);
    }
}

//Geometry
void TestGeometrySphere() {
    auto material_green = make_shared<Lambertian>(dvec3(0.8, 0.8, 0.0));
    if (Sphere(dvec3(0, 0, -100.5), 100, material_green)) {
        printf(true);
    } else {
        prinf(false);
    }
}

//Material

//Renderer
void TestRendererRaytracer() {
    if (Raytracer) {
        printf(true);
    } else {
        printf(false);
    }
}

void TestRendererRenderer() {
    if (Renderer()) {
        printf(true);
    } else {
        printf(false);
    }
}

void TestRendererRenderTargetPass() {
    if (RenderTarget()) {
        printf(true);
    } else {
        printf(false);
    }
}

//Scene
void TestScene() {
    if Scene() {
        printf(true);
    } else {
        printf(false);
    }
}

//Utils
void TestUtilsHeaders() {
    if HEADERS_H {
        printf(true);
    } else {
        printf(false);
    }
}
