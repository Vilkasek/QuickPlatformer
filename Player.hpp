#include "raylib.h"

// Player structure
struct Player
{
    // Texture and collision box
    Texture2D tex = { 0 };
    Rectangle collBox = { 0 };

    // Movement velocity
    Vector2 velocity = { 0 };

    // Speed and gravity
    float speed = 10.f;
    float grav = 1.f;
};