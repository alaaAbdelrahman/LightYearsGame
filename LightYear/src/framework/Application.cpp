

#include<iostream>

#include "framework/Application.h"


using namespace ly;

    Application::Application()
                :mWindow{sf::VideoMode(1024,1440),"Light Years"},
                mTargetFrameRate{30.f},
                mTickClock{}
    {

    }

    void Application::Run()
    {
        mTickClock.restart();  // to make begin count from that point, Notice restart method return time
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f /mTargetFrameRate; // convert frquency to time 

        while (mWindow.isOpen())
        {
            sf::Event windowEvent;
            while(mWindow.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    mWindow.close();
                }
            }

            // store the time the process taken and convert to float as Seconds
            accumulatedTime += mTickClock.restart().asSeconds(); 
            while(accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                Tick(targetDeltaTime);
            }


        }
        
    }

 void Application::Tick(float deltaTime){

    std::cout<< "ticking at frame Rate: "<<1.f/deltaTime<<std::endl;
 }