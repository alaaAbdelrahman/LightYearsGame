#include "framework/Core.h"
#include "framework/World.h"
#include"gameFramework/GameApplication.h"

ly::Application * GetApplication(){

    return new ly::GameApplication{};
}
namespace ly
{
    GameApplication::GameApplication(){

     std::weak_ptr<World> newWorld = LoadWorld<World>();
     newWorld.lock()->SpawnActor<Actor>();
     

    }
}
