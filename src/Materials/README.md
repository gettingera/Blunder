# Materials

Materials are interactions with light that define how they appear when viewed. For example, a shiny mirror reflects
light very sharply whereas a lightbulb must be transparent to allow light to pass through.

# Types of Materials

- Material
    - An abstract class defining the essential scatter property, defining how light will scatter when interacted with
      the material.
- Lambertian
    - A matte material which appears very soft and diffuse. Has a color attribute.
- Metal
    - A metal material which can appear very reflective, or fuzzed if desired. Has a fuzziness and a color attribute.
- Dielectric
    - A glass material which has reflective and refractive qualities.