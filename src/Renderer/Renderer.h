#ifndef RENDERER_H
#define RENDERER_H


#include "Scene/Scene.h"
#include "RenderTarget.h"


class Renderer {
public:
    // Constructor
    Renderer() = default;

    // Methods
    virtual void Render(const shared_ptr<Scene> &scene, const shared_ptr<RenderTarget> &render_target) = 0;

    // Destructor
    virtual ~Renderer() = default;
};


#endif //RENDERER_H
