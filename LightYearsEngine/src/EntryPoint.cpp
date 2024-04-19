#include "EntryPoint.h"
#include "framework/Application.h"
#include<iostream>
#include "framework/Core.h"

int main(){

ly::Application * app = GetApplication();
app->Run();
std::cout<<"hello\n";
LOG("Welcome\n");

delete app;

    return 0;
}