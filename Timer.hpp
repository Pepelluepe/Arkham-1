#ifndef TIMER_HPP
#define TIMER_HPP

#include "SDL.h"

/**
    * TIMER CLASS.
    * This class measures time.
    * It's using SDL_GetTicks(), so it includes "SDL.h"
    * Measures time in miliseconds.
*/

class Timer
{
    Uint32 startTicks;
    Uint32 pausedTicks;

    bool started;
    bool paused;

public:
    //Default constructor of Timer. Setting everything to 0 and false.
    Timer();
    //Start counting time. It basically sets startTicks to current ticks from SDL_GetTicks(), and sets started to true.
    void Start();
    //Set flags to false.
    void Stop();
    //Keeps value of ticks when timer has stopped. Will be used to resume timer.
    void Pause();
    //starts counting time from the stopped time.
    void Unpause();
    //Return startTicks(if running), pausedTicks(if paused), or 0 if timer isn't started
    Uint32 GetTicks();

    inline bool IsPaused() { return paused;};
    inline bool IsStarted() { return started;};
    inline auto GetCurrentTime() -> decltype(SDL_GetTicks()) { return SDL_GetTicks(); }
};

#endif // TIMER_HPP
