#ifndef WORLD_H_
#define WORLD_H_
#include "framework/Actor.h"

namespace ly
{
    //forward declarato]ion for Application class
    class Actor;
    class Application;

    class World{
        public:
             World(Application * owningApp);

             void BeginPlayInternal();
             void TickInternal(float deltaTime);
             virtual ~World();

    template<typename ActorType>
    weak<ActorType> SpawnActor() {
    shared<ActorType> newActor{new ActorType{this}};
    mPendingActors.push_back(newActor);
    return weak<ActorType>(newActor);
}

        private:
             void BeginPlay();
             void Tick(float deltaTime);
             Application * mOwningApp;
             bool mBeganPlay;

             List<shared<Actor>> mActors;
             List<shared<Actor>> mPendingActors;


    };
    
}


#endif