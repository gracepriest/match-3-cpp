#include "include/raylib.h"
//#include "Timer.h"
//#include "GameTween.h"
#include "Game.h"


//change win32 to x64 if you on 64 platform or win32 on x86
//also go in lib/ that matches platform folder copy paste raylib.dll to main dir
#pragma comment(lib,"lib/x64/raylibdll.lib")


int main()
{
    // Initialization
   //--------------------------------------------------------------------------------------
    /*const int screenWidth = 800;
    const int screenHeight = 450;
    Timer t = Timer();
    float dt = 0;

    int currentSecond = 0;
    int counter = 0;

    Timer time;
    char message[10] = { "hey" };
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");*/

    Game GameApp;

    GameApp.Start();

    return 0;
}

//int main()
//{
//    // Initialization
//   //--------------------------------------------------------------------------------------
//    const int screenWidth = 800;
//    const int screenHeight = 450;
//    Timer t = Timer();
//    float dt = 0;
//    int currentSecond = 0;
//    int counter = 0;
//    auto tween =  tweeny::from(255,0,0,255).to(0,0,0,255).during(150) ;
//    auto tw = tween.step(1);
//    Color cw = {(unsigned char)tw[0],(unsigned char)tw[1],(unsigned char)tw[2],(unsigned char)tw[3]};
//    auto tween2 = tweeny::from(cw).to(Color{ (unsigned char)0, (unsigned char)0, (unsigned char)0,(unsigned char)255 }).during(150);
//    Timer time;
//    char message[10] = { "hey" };
//    GameTween gTween;
//    
//    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
//
//   
//
//    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
//    //--------------------------------------------------------------------------------------
//    time.every([&]()
//        {
//            currentSecond++;
//            strcpy_s(message, std::to_string(currentSecond).c_str());
//        }, 500,10);
//    
//    // Main game loop
//    while (!WindowShouldClose())    // Detect window close button or ESC key
//    {
//        
//        // Update
//        //----------------------------------------------------------------------------------
//        // TODO: Update your variables here
//        //----------------------------------------------------------------------------------
//        dt = GetFrameTime();
//        // Draw
//        //----------------------------------------------------------------------------------
//        BeginDrawing();
//
//        ClearBackground(BLACK);
//       
//        DrawText(message, 600, 300, 100, WHITE);
//        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//        //tw = tween.step(dt);
//        //cw = { (unsigned char)tw[0],(unsigned char)tw[1],(unsigned char)tw[2],(unsigned char)tw[3] };
//        //if (counter == 0)
//        //{
//        //    //time.every(&gTween,1,3);
//        //    counter++;
//        //   // gTween.tween(cw, DARKBLUE, 15, 20).tween(cw, RED, 15, 20).tween(cw, DARKBLUE, 15, 20).tween(cw, RED, 15, 20);
//        //    
//        //}
//        DrawTexture(Boradvf, 0, 0, RAYWHITE);
//       
//        DrawText("Congrats! You created your first window!", 190, 200, 50, cw);
//
//        EndDrawing();
//        //----------------------------------------------------------------------------------
//    }
//
//    // De-Initialization
//    //--------------------------------------------------------------------------------------
//    CloseWindow();        // Close window and OpenGL context
//    //--------------------------------------------------------------------------------------
//
//    return 0;
//
//
//
//
//
//    /* if (counter < 1)
//        {
//            time.every([&]()
//                {
//                    currentSecond++;
//                    strcpy_s(message, std::to_string(currentSecond).c_str());
//                }, 1);
//            counter++;
//        }
//        else if (currentSecond >= 10)
//        {
//            time.stop();
//        }*/
//}