#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    Texture2D cubeTex = LoadTexture("sprites/tile.png");

    float scale = 3.0f;

    float tileWidth = cubeTex.width * scale;   // weil du scale=0.2f benutzt
    float tileHeight = (cubeTex.height / 2) * scale;

    float posX1 = 0.0f;
    float posY1 = 0.0f;
    float posX2 = 2.0f;
    float posY2 = 1.0f;


    float playerPosX = 0.0f;
    float playerPosY = 0.0f;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);


            float mapPosX = 500.0f;
            float mapPosY = 100.0f;

            float mapPosX2 = 500.0f;
            float mapPosY2 = 100.0f;

            float heightOffset = cubeTex.height / 2 * scale;
            

            for(int x = 0; x<15; x++)
            {
                for(int y = 0; y<15; y++)
                {
                    posX2 = x;
                    posY2 = y;
                    float offsetY = 0.0f;

                    if(x == 7 && y == 7)
                    {
                        offsetY = 7.0f;
                    }

                    auto isometricX2 = ((posX2 - posY2) * tileWidth/2);
                    auto isometricY2 = ((posX2 + posY2) * tileHeight/2);
                    DrawTextureEx(cubeTex, (Vector2){isometricX2 + mapPosX, isometricY2 + mapPosY - offsetY}, 0.0f, scale, WHITE);
                }
            }

            for(int x = 0; x<15; x++)
            {
                for(int y = 0; y<15; y++)
                {
                    posX2 = x;
                    posY2 = y;

                    auto isometricX2 = ((posX2 - posY2) * tileWidth/2);
                    auto isometricY2 = ((posX2 + posY2) * tileHeight/2);


                    if(x == 0 || x == 14 || y == 0 || y == 14)
                    {
                        DrawTextureEx(cubeTex, (Vector2){isometricX2 + mapPosX2, isometricY2 + mapPosY2 - heightOffset}, 0.0f, scale, RED);
                    }
                }
            }

            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}