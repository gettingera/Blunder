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
void TestGeometryHitRecordPass(void);
void TestGeometryHitRecordFail(void);

void TestGeometryHittablePass(void);
void TestGeometryHittableFail(void);

void TestGeometryHittableListPass(void);
void TestGeometryHittableListFail(void);

void TestGeometrySpherePass(void);
void TestGeometrySphereFail(void);

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
    TestGeometryHitRecordPass();
    TestGeometryHitRecordFail();

    TestGeometryHittablePass();
    TestGeometryHittableFail();

    TestGeometryHittableListPass();
    TestGeometryHittableListFail();

    TestGeometrySpherePass();
    TestGeometrySphereFail();
    

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
    float width = 5.0f;
    float height = 6.0f;
    RenderTarget(width, height);
}

void TestGeometryHitRecordPass() {
    HitRecord();
}

void TestGeometryHitRecordFail() {
    HitRecord();
}

void TestGeometryHittableListPass() {
    HittableList();
}

void TestGeometryHittableListFail() {
    HittableList();
}

void TestGeometrySpherePass() {
    Sphere();
}

void TestGeometrySphereFail() {
    Sphere();
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