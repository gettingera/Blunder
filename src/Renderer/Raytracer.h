#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Renderer.h"
#include "RenderTarget.h"


class Raytracer : public Renderer {
  public:
    RenderTarget* Render(Scene* scene);

  private:
};


#endif //RAYTRACER_H
