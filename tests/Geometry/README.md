# Geometries

Geometries define interactive objects in the world. These can be abstract classes, or more directly definable objects
such as spheres, triangles, planes, and other primitives.

# Types of Geometries

- Hittable
    - The most fundamental form of geometry. This abstract class allows rays to interact with the object in a custom
      manner defined by its child classes.
- HitRecord
    - Nothing more than a containerized list of information recording the information from ray-hittable intersections.
- HittableList
    - A direct step up from a Hittable, it simply extends the logic to a list of objects.
- Axis Aligned Bounding Box (AABB)
    - A simple box that entirely covers a Hittable object. These are very cheap to calculate intersection tests, making
      it a simple optimization for complex geometries and a requirement for Bounding Volume Hierarchies.
- Bounding Volume Hierarchy (BVH) Node
    - A data structure which partitions collections of objects into a tree of AABBs, each getting progressively smaller.
      In scenes with many objects spaced uniformly, exponential speed-ups of rendering are guaranteed.
    - The base cost incurred by this data structure should be avoided for scenes with very few items.
- Sphere
    - A basic sphere object. It has a position at the beginning of the frame, and a position at the end of the frame for
      calculating motion blur. It also contains a radius and a material.
- Triangle
    - The most basic mesh primitive. It has three vertices with positions at the beginning and the end of each frame, as
      well as a material.