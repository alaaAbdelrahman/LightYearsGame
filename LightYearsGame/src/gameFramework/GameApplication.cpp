#include"gameFramework/GameApplication.h"

ly::Application * GetApplication(){

    return new ly::GameApplication{};
}