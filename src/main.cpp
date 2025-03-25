// Includes
#define GLM_ENABLE_EXPERIMENTAL

#include "Utils/headers.h"
#include "Renderer/RenderTarget.h"
#include "Geometry/HittableList.h"
#include "Geometry/Sphere.h"
#include "Scene/Scene.h"
#include "Renderer/Raytracer.h"

// Macros

// Prototypes

// Main method
int main() {
    auto world = std::make_shared<HittableList>();
    auto camera = std::make_shared<Camera>();
    auto settings = std::make_shared<SceneSettings>();
    auto scene = std::make_shared<Scene>();

    scene->world = world;
    scene->camera = camera;
    scene->settings = settings;

    // Add spheres to world
    world->Add(std::make_shared<Sphere>(glm::dvec3(0), 1));
    world->Add(std::make_shared<Sphere>(glm::dvec3(1), .5));
    world->Add(std::make_shared<Sphere>(glm::dvec3(2), .25));

    // Configure camera
    camera->position = glm::dvec3(-2, 0, 0);
    camera->direction = glm::dvec3(0, 0, 0);

    // Configure settings
    settings->width = 100;
    settings->height = 100;

    // Render
    const auto rt = std::make_shared<Raytracer>();
    auto rtt = rt->Render(scene);
    rtt->WriteToFile("testrender.ppm");


}

// Implementations
