#ifndef ATCOR_H_
#define ATCOR_H_

namespace ly
{   //forward declration 

    class World;

    class Actor
    {
    public:
        Actor(World * owningWorld);
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        virtual ~Actor();
    
    private:
    World * mOwningWorld;
    bool mHasBeganPlay;
        
    };
    
    

    
}



#endif // !ATCOR_H_
