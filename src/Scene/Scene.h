#ifndef SCENE_H
#define SCENE_H


#include "Geometry/HittableList.h"
#include "Camera/Camera.h"


struct Scene {
    std::shared_ptr<HittableList> world;
    std::shared_ptr<Camera> camera;
};


#endif //SCENE_H
