#include "framework/Core.h"
#include "framework/Actor.h"
namespace ly
{

    Actor::Actor(World *owningWorld)
    :mOwningWorld{owningWorld},
    mHasBeganPlay{false}
    {
    }
    Actor::~Actor(){

    }
    void Actor::BeginPlayInternal(){
        if(!mHasBeganPlay){
            mHasBeganPlay= true;
            BeginPlay();
        }
    }
    void Actor::BeginPlay(){
        LOG("Actor begin Play");
    }
    void Actor::Tick(float deltaTime){

         LOG("Actor Ticking"); 

    }
    

    

    
}