#include "raylib.h"

// Gamestates
enum class GameStates
{
    GAME,
};

// Initial gamestate
GameStates gameState = GameStates::GAME;

// Initial screen size
const int sWidth = 1280;
const int sHeight = 720;

// Init stuff
void init();

// Updating stuff
void gameUpdate();
void update();

// Rendering stuff
void gameRender();
void render();

// Deinitialization stuff
void deinit();

// Program's main function
int main()
{
    init();

    // Main game loop
    while (!WindowShouldClose())
    {
        render();
    }

    deinit();
}

// Init game components
void init()
{
    // Create window
    InitWindow(sWidth, sHeight, "Quick Platformer");

    // Set FPS target
    SetTargetFPS(60);
}

// Update game components
void gameUpdate()
{

}
void update()
{
    // Updating depend on gamestate
    switch(gameState)
    {
    case GameStates::GAME:
        gameUpdate();
        break;
    }
}

// Render game components
void gameRender()
{
    ClearBackground(WHITE);

    BeginDrawing();

    EndDrawing();
}
void render()
{
    // Rendering depend on gamestate
    switch (gameState) 
    {
    case GameStates::GAME:
        gameRender();
        break;
    }
}

// Deinitialization game components
void deinit()
{
    CloseWindow();
}
