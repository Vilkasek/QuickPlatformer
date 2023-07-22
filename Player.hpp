#include "raylib.h"

// Player structure
struct Player
{
    // Texture and collision box
    Texture2D tex = { 0 };
    Rectangle collBox = { 0 };

    // Movement velocity and position
    Vector2 velocity = { 0 };
    Vector2 position = { 0 };

    // Speed and gravity
    float speed = 10.f;
    float grav = 5.f;

    // Player update
    void update()
    {
        velocity = (Vector2){0, grav};

        if (IsKeyDown(KEY_A)) velocity.x -= speed;
        if (IsKeyDown(KEY_D)) velocity.x += speed;

        if (IsKeyPressed(KEY_SPACE)) grav = grav * -1;

        position.x += velocity.x;
        position.y += velocity.y;
    }

    // Player render
    void render()
    {
        DrawTextureEx(tex, position, 0.f, 3.f, WHITE);
    }

    // Player deinit
    void deinit()
    {
        UnloadTexture(tex);
    }
};