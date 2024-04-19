

#include<iostream>
#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h"


using namespace ly;

    Application::Application()
                :mWindow{sf::VideoMode(1024,1440),"Light Years"},
                mTargetFrameRate{30.f},
                mTickClock{},
                currentWorld{nullptr}
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
                TickInternal(targetDeltaTime);
                RenderInternal();
            }


        }
        
    }

 void Application::TickInternal(float deltaTime){
       
     Tick(deltaTime);

    if(currentWorld){
        currentWorld->BeginPlayInternal();
        currentWorld->TickInternal(deltaTime);

    }
     

 }

void Application:: RenderInternal(){
    //clear and display the changes by render
    mWindow.clear();

    // virtual function so the client can use it to render what it want 
    Render();

    //display what renedered
    mWindow.display();
    
}

void Application:: Render(){

    sf::CircleShape circle(50);

    circle.setFillColor(sf::Color::Green);

    circle.setOrigin(50,50);

    circle.setPosition(mWindow.getSize().x/2.f,mWindow.getSize().y/2.f );

    mWindow.draw(circle);
}
void Application::Tick(float deltaTime){

    LOG("ticking at framerate %f",(1.f/deltaTime));

}

