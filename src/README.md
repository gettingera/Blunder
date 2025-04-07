# Source Code

The code structure for Blunder follows OOP (Object-Oriented Programming) design principles.
Classes that have logical relations are grouped in similar folders.

The project files follow a strict header-implementation structure. Class definitions and interfaces are defined in the
header (.h) files, whereas the code implementations are found in the source (.cpp) files.

# Tests

Tests can be found in the [tests folder](../tests).

# Documentation

General project documentation may be found in the [documentation folder](../docs).

For general code documentation, refer to the links at the bottom of the page.

For specific code documentation (specifically doxygen-generated documentation), build the project and identify the
index.html file generated in the [documentation folder](../docs).

# Executable Code

[main.cpp](./main.cpp) -> Program entry point.

# Classes

[Camera](./Camera) -> 3D Camera.

[Geometry](./Geometry) -> Sphere class and all related objects.

[Renderer](./Renderer) -> Renderer class encapsulating the ray tracing logic.

[Utils](./Utils) -> Utility classes and functions.


