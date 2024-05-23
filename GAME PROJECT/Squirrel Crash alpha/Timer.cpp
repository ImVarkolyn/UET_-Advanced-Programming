#include "Timer.h"
#include "CommonFunc.h"

Timer::Timer()
{
    start_tick =0;
    paused_tick =0;
    is_paused = false;
    is_started = false;

}

Timer::~Timer()
{

}

void Timer::start()
{
    is_started = true;
    is_paused = false;
    start_tick = SDL_GetTicks();
}

void Timer::stop()
{
    is_paused = false;
    is_started = false;
}

void Timer::paused()
{
    if (is_started == true && is_paused == false)
    {
        is_paused = true;
        paused_tick = SDL_GetTicks() - start_tick;
    }
}

void Timer::unpaused()
{
    if (is_paused == true)
    {
        is_paused = true;
        start_tick = SDL_GetTicks() - paused_tick;
        paused_tick =0;
    }
}

int Timer::get_tick()
{
    if (is_started == true)
    {
        if (is_paused == true)
        {
            return paused_tick;
        }
        else
            return SDL_GetTicks() - start_tick;
    }

    return 0;
}

bool Timer::is_Started()
{
    return is_started;
}

bool Timer::is_Paused()
{
    return is_paused;
}


