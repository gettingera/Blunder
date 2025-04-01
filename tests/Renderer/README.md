# Renderer

A renderer applies the properties of materials and incoming light sources to visualize a 3d scene to a 2d image.

# Utilities

- Render Target
    - Also known as a render buffer or image buffer, it is a 2d image residing in memory. It is a very simple class
      designed to allow renderers to write pixels to it, and to output to any arbitrary format. (file, screen, custom
      formats)

# Types of Renderers

- Renderer
    - An abstract renderer which defines the Render property which will take in a scene and render it to a render
      target.
- Raytracer
    - A renderer which uses the properties defined in [Materials](../Materials) and [Geometry](../Geometry) to create
      photorealistic renders of virtual scenes. 