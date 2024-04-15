#ifndef  APLICATION_H_
#define APLICATION_H_

#include <SFML/Graphics.hpp>

namespace ly
{
    class Application
    {
    public:
        Application();
        void Run();
        
    
    private:
    void Tick(float deltaTime);


    sf::RenderWindow mWindow;
    sf::Clock mTickClock;        // to get the time 

    float mTargetFrameRate;     // to define the frame rate frequency
        
    };
    
   
}





#endif // ! APLICATION_H_
