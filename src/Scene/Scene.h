#ifndef SCENE_H
#define SCENE_H


#include <memory>
#include "Geometry/HittableList.h"
#include "Camera/Camera.h"
#include "SceneSettings.h"


class Scene {
  public:
    // Constructor
    Scene(std::shared_ptr<HittableList> world, std::shared_ptr<Camera> camera, std::shared_ptr<SceneSettings> settings) {
      this->world = world;
      this->camera = camera;
      this->settings = settings;
    }

  private:
    // Attributes
  std::shared_ptr<HittableList> world;
  std::shared_ptr<Camera> camera;
  std::shared_ptr<SceneSettings> settings;
};



#endif //SCENE_H
