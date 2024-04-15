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
    sf::RenderWindow mWindow;
        
    };
    
   
}





#endif // ! APLICATION_H_
