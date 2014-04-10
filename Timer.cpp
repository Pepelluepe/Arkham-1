#include "Timer.hpp"

Timer::Timer()
{
    //Set everything to default(0 or false)
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

void Timer::Start()
{
    //Set flags
    started = true;
    paused = false;
    //Start counting time
    startTicks = SDL_GetTicks();
}

void Timer::Stop()
{
    //Zero flags. Everything else will be cleaned up in proper starting functions
    started = false;
    paused = false;
}

void Timer::Pause()
{
    //If program isn't paused, and is running
    if( started && (!paused) )
    {
        //Pause
        paused = true;
        //Get time of pause
        pausedTicks = SDL_GetTicks() - startTicks;
    }

}

void Timer::Unpause()
{
    //If program is paused(can only be paused when running)
    if( paused )
    {
        //Start from last paused time
        startTicks = SDL_GetTicks() - pausedTicks;
        //Zero pause things.
        pausedTicks = 0;
        paused = false;
    }
}

Uint32 Timer::GetTicks()
{
    if(started)
    {
        if( paused )
        {
            return pausedTicks;
        }
        else
        {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;

}
