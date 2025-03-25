#ifndef SCENE_H
#define SCENE_H


#include "Geometry/HittableList.h"
#include "Camera/Camera.h"
#include "SceneSettings.h"


struct Scene {
    std::shared_ptr<HittableList> world;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<SceneSettings> settings;
};


#endif //SCENE_H
