#ifndef RENDERER_H
#define RENDERER_H


#include "Scene/Scene.h"
#include "RenderTarget.h"


class Renderer {
  public:
    // Methods
    virtual RenderTarget* Render(Scene* scene);
};


#endif //RENDERER_H
