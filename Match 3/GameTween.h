#pragma once
#include "include/tweeny.h"
#include "include/raylib.h"
#include "Timer.h"
#include <queue>
#include <mutex>
#include <thread>


class GameTween 
{
public:
    bool Isfinish = true;
    std::mutex mtx;
    
    GameTween() {};
	
    GameTween& tween(Color& color, Color myColor, int RATE, int dura)
    {
        bool localFinish = false;
       
        std::thread t([=,&color, &localFinish](int counter = 0)
        {             
               mtx.lock();
               auto tween = tweeny::from(color.r, color.g, color.b, color.a).to(myColor.r, myColor.g, myColor.b, myColor.a).during(dura);
               auto tw = tween.step(1);

               while (true)
               {
                                    
                     for(int i=0;i<=dura;i++)
                     {
                           
                           std::this_thread::sleep_for(std::chrono::milliseconds(RATE));
                           tw = tween.step(1);
                           if (tween.progress() == 1)
                           {
                               
                               finish();
                               localFinish = true;
                               break;
                           }
                           color = { (unsigned char)tw[0],(unsigned char)tw[1],(unsigned char)tw[2],(unsigned char)tw[3] };
                           counter += 1;   
                          
                     } 
                                 
                   if (localFinish == true) break;
                   else
                   {
                       tween = tweeny::from(color.r, color.g, color.b, color.a).to(myColor.r, myColor.g, myColor.b, myColor.a).during(dura);
                       continue;
                   }
                   
               }
               mtx.unlock();
        });    
        t.detach();
           
      return *this;
     
	}

    GameTween& tween(Color& color, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0,
                             unsigned char a = 0,int RATE = 25, int duration = 150)
    {
        std::thread t([=, &color]() {
            int counter = 0;
            unsigned char oringalColor[4] = { color.r,color.g,color.b,color.a };
            unsigned char newColor[4] = { r,g,b,a };
            //check to see if there a value in myColor     
                auto tween = tweeny::from(oringalColor[0], oringalColor[1], oringalColor[2], oringalColor[3]).to(newColor[0], newColor[1], newColor[2], newColor[3]).during(duration);
                auto tw = tween.step(1);
                while (counter < duration)
                {
                    tw = tween.step(1);
                   
                    std::this_thread::sleep_for(std::chrono::milliseconds(RATE));
                    color = { (unsigned char)tw[0],(unsigned char)tw[1],(unsigned char)tw[2],(unsigned char)tw[3]};
                    counter += 1;
                }
            });

       
      t.detach();
      return *this;
    }

    
      GameTween &finish() {
        std::cout << "IT WORKS ";
        return *this;
    }
};