#ifndef SCENE_H
#define SCENE_H


#include "Geometry/HittableList.h"
#include "Camera/Camera.h"


class Scene {
  public:

  private:
    // Attributes
    HittableList world;
    Camera camera;
};



#endif //SCENE_H
