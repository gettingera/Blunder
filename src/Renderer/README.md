# Renderer
A renderer applies the properties of materials and incoming light sources to visualize a 3d scene to a 2d image.
This renderer uses ray tracing to create photorealistic images of digital spheres.

# Utilities

## Render Target
Also known as a render buffer or image buffer, it is a 2d image residing in memory. It is a very simple class designed
to allow renderers to write pixels to it, and to output to any arbitrary format. (file, screen, custom formats)
