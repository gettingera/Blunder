# Camera

The camera is essential for viewing 3d scenes. This camera utility class provides a container for many options the user
may choose.

# Options

- Position
    - The position in the world the camera is located.
- Direction
    - The point in the world the camera is viewing.
- Up Direction
    - A universally accepted basis for what direction is considered 'upward' in the world. The default value is Z+ Up.
- Vertical Field of View
    - The angle between the top and the bottom of the camera, measured in degrees. It measures how widely the camera
      views the scene. The default value is 60 degrees.
- Focus Distance
    - The distance away from the camera origin that will be in perfect clarity and focus. Objects nearer and farther
      than this distance will have a subtle blurring, known as depth of field.
- Focus Angle
    - The amount of blurring away from the focus distance. This is also known as the aperture of the lens.