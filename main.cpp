#include "Player.hpp"
#include <raylib.h>

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

// Create game objects
Player player;

// Init stuff
void initPlayer();
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
        update();
        render();
    }

    deinit();
}

// Init game components
void playerInit()
{
    player.tex = LoadTexture("./Textures/Player/Bot.png");

    player.collBox = { player.position.x, player.position.y, (float)player.tex.width, (float)player.tex.height };

    player.position = (Vector2){120, 10};
}
void init()
{
    // Create window
    InitWindow(sWidth, sHeight, "Quick Platformer");

    // Set FPS target
    SetTargetFPS(60);

    // Init other components
    playerInit();
}

// Update game components
void gameUpdate()
{
    player.update();
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
    ClearBackground(VIOLET);

    BeginDrawing();

    player.render();

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
    player.deinit();

    CloseWindow();
}
