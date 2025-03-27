#ifndef SCENE_H
#define SCENE_H
#include "Geometry/HittableList.h"
#include "Camera/Camera.h"


/**
 * Scene structure containing the renderable world and a camera to view it with.
 *
 * Useful for efficient simplified access of worlds and cameras, and offers flexibility with shared pointers.
 */
struct Scene {
    /// List of hittable objects.
    shared_ptr<HittableList> world;

    /// Camera to view objects with.
    shared_ptr<Camera> camera;
};


#endif //SCENE_H
