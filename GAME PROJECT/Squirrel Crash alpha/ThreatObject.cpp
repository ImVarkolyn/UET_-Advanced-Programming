#include "ThreatObject.h"
#include <iostream>

ThreatObject::ThreatObject()
{
    rect.x = SCREEN_WIDTH;
    rect.y = SCREEN_HEIGHT * 0.5;
    rect.w = THREAT_SIZE;
    rect.h = THREAT_SIZE;
    x_val = 0;
    y_val = 0;
}

ThreatObject::~ThreatObject()
{

}

void ThreatObject::HandleMove(const int& x_border, const int& y_border)
{
    rect.x -= x_val;
    if (rect.x < 0)
    {
        rect.x = x_border;
        int rand_y = rand() % (y_border - THREAT_SIZE);
        if (rand_y > y_border - THREAT_SIZE)
        {
            rand_y = y_border * 0.5;
        }
        rect.y = rand_y;
    }
}

void ThreatObject::HandleInputAction(SDL_Event events)
{
    // TODO
}

void ThreatObject::Reset(const int& x_border, const int& y_border)
{
    rect.x = x_border;
    int rand_y = rand() % (y_border - THREAT_SIZE);
    if (rand_y > y_border - THREAT_SIZE)
    {
        rand_y = y_border * 0.5;
    }
    rect.y = rand_y;

}
