#ifndef  APLICATION_H_
#define APLICATION_H_

#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
    class World;  //forward Declaration
    class Application
    {
    public:
        Application();
        void Run();
        template<typename WorldType>
        std::weak_ptr<WorldType> LoadWorld()
        {
            shared<WorldType> newWorld{new WorldType{this}};
            currentWorld = newWorld;
            return newWorld;
        }
        
    
    private:
    void TickInternal(float deltaTime);
    virtual void Tick(float deltaTime);
    void RenderInternal();
    virtual void Render();


    sf::RenderWindow mWindow;
    sf::Clock mTickClock;        // to get the time 
    float mTargetFrameRate;     // to define the frame rate frequency
    shared<World> currentWorld;  
    };
    
   
}
 


#endif // ! APLICATION_H_
