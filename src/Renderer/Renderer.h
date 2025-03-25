#ifndef RENDERER_H
#define RENDERER_H


#include "Scene/Scene.h"
#include "RenderTarget.h"


class Renderer {
public:
    // Constructor
    Renderer() = default;

    // Methods
    virtual std::shared_ptr<RenderTarget> Render(std::shared_ptr<Scene> scene) = 0;

    // Destructor
    virtual ~Renderer() = default;
};


#endif //RENDERER_H
