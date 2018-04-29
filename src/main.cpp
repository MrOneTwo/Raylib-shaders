/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera free
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_STYLE_SAVE_LOAD  // uses image as a style
#include "raygui.h"
#define STB_SPRINTF_IMPLEMENTATION
#include "stb_sprintf.h"

#include "color_palette.h"
#include "tween.h"

#include <stdlib.h>
#include <stdint.h>
#include <iostream>



const int windowWidth = 1366;
const int windowHeight = 768;


int main(int argc, char * argv[])
{
  // Initialization
  //--------------------------------------------------------------------------------------
  bool running = true;

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  SetConfigFlags(FLAG_VSYNC_HINT);
  InitWindow(windowWidth, windowHeight, "raylib [core] example - 3d camera free");

  SetTargetFPS(90);                   // Set our game to run at 60 frames-per-second

  GuiLoadStyleImage("./rguistyle_default_dark.png");
  SpriteFont fontTTF = LoadSpriteFont("./RenogareSoft-Regular.ttf");
  SpriteFont fontPNG = LoadSpriteFont("./RenogareSoft-Regular-SpriteSheet.fnt");

  bool mouseEnteredStart = false;
  bool mouseEnteredStartPrev = false;
  bool mouseEnteredQuit = false;
  bool mouseEnteredQuitPrev = false;
  bool mouseEnteredShaderTwo = false;
  bool mouseEnteredShaderTwoPrev = false;

  int rows = 66;
  int cols = 54;
  int margin = 8;

  Shader shaderOne = LoadShader("resources/shaders/base.vs",
    "resources/shaders/pattern_circle.fs");
  Shader shaderTwo = LoadShader("resources/shaders/base.vs",
    "resources/shaders/pattern_rectangle_mouse_coords.fs");

  int mousePositionLocation = GetShaderLocation(shaderTwo, "mousePosition");
  float mousePosition[2] = {-1.0f, -1.0f};
  //--------------------------------------------------------------------------------------

  while (running)
  {
    if (WindowShouldClose())
    {
      running = false;
    }

    // Update
    //----------------------------------------------------------------------------------
    unsigned char timingLabel[64];
    float dt = GetFrameTime();
    stbsp_sprintf(timingLabel, "Frame dt: %f", dt);


    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(COLOR_PALETTE_GREY);

    BeginShaderMode(shaderOne);
    DrawRectangle(32, 32, 256, 256, RED);
    EndShaderMode();

    BeginShaderMode(shaderTwo);
    DrawRectangle(32 + 256 + 32, 32, 256, 256, RED);
    EndShaderMode();

    // GUI
    GuiLabel((Rectangle){8, windowHeight - 16, 40, 16}, timingLabel);
    DrawTextEx(fontPNG, "START", (Vector2){384/2 - 130 - 30, 500}, 78, 0, COLOR_PALETTE_RED);
    DrawTextEx(fontPNG, "QUIT", (Vector2){384/2 - 130 - 30, 569}, 78, 0, COLOR_PALETTE_RED);


    mouseEnteredStartPrev = mouseEnteredStart;
    mouseEnteredStart = (CheckCollisionPointRec(GetMousePosition(), (Rectangle){0, 0, 432, 768-243})) ? true : false;
    mouseEnteredQuitPrev = mouseEnteredQuit;
    mouseEnteredQuit = (CheckCollisionPointRec(GetMousePosition(), (Rectangle){0, 768-243, 432, 243})) ? true : false;

    mouseEnteredShaderTwoPrev = mouseEnteredShaderTwo;
    mouseEnteredShaderTwo = (CheckCollisionPointRec(GetMousePosition(), (Rectangle){32 + 256 + 32, 32, 256, 256})) ? true : false;

    if (mouseEnteredShaderTwo) {
      mousePosition[0] = (float)(GetMousePosition().x - (32 + 256 + 32))/256;
      mousePosition[1] = (float)(GetMousePosition().y - 32)/256;
      SetShaderValue(shaderTwo, mousePositionLocation, mousePosition, 2);
    } else {
      mousePosition[0] = -1.0f;
      mousePosition[1] = -1.0f;
      SetShaderValue(shaderTwo, mousePositionLocation, mousePosition, 2);
    }

    if(GuiButton((Rectangle){ windowWidth - 80, windowHeight - 80, 70, 30 }, FormatText("EXIT")))
    {
      running = false;
    }
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      int x = GetMousePosition().x;
      int y = GetMousePosition().y;
      printf("Mouse X: %d ,  Y: %d \n", x, y);
    }

    DrawFPS(10, 10);
    EndDrawing();
  }

  //----------------------------------------------------------------------------------

  CloseWindow();        // Close window and OpenGL context
  return 0;
}
