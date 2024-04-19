#ifndef WORLD_H_
#define WORLD_H_

namespace ly
{
    //forward declarato]ion for Application class
    class Application;

    class World{
        public:
             World(Application * owningApp);

             void BeginPlayInternal();
             void TickInternal(float deltaTime);
             virtual ~World();

        private:
             void BeginPlay();
             void Tick(float deltaTime);
             Application * mOwningApp;
             bool mBeganPlay;


    };
    
}


#endif