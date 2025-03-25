#ifndef SCENE_H
#define SCENE_H


#include "Geometry/HittableList.h"
#include "Camera/Camera.h"


struct Scene {
    shared_ptr<HittableList> world;
    shared_ptr<Camera> camera;
};


#endif //SCENE_H
