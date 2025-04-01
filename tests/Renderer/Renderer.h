#ifndef RENDERER_H
#define RENDERER_H
#include "Scene/Scene.h"
#include "RenderTarget.h"


/**
 * Abstract renderer class.
 *
 * Useful for having maximum modularity with different rendering methodologies.
 */
class Renderer {
public:
    // Constructor
    Renderer() = default;

    // Methods
    /**
     * Virtual render function to render scene into a render target.
     *
     * @param scene Scene to be rendered.
     * @param render_target Render target to be rendered to.
     */
    virtual void Render(const Scene &scene, const shared_ptr<RenderTarget> &render_target) = 0;

    // Destructor
    virtual ~Renderer() = default;
};


#endif //RENDERER_H
