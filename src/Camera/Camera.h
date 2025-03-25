#ifndef CAMERA_H
#define CAMERA_H


struct Camera {
    // Where I am, where I am looking to
    glm::dvec3 position;
    glm::dvec3 direction;

    // Vector designated to be upwards direction
    glm::dvec3 up;

    // Some other settings
    double vfov;
};


#endif //CAMERA_H
