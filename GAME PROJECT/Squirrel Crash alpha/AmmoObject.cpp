#include "AmmoObject.h"
#include <iostream>

AmmoObject::AmmoObject()
{
    x_val = 0;
    y_val = 0;
    is_move = false;
}

AmmoObject::~AmmoObject()
{

}

void AmmoObject::HandleMove(const int& x_border, const int& y_border)
{
    if (is_move)
    {
        if (ammo_dir == DIR_RIGHT)
        {
            rect.x += x_val;
            if (rect.x > x_border)
            {
                is_move = false;
            }
        }
        else if (ammo_dir == DIR_LEFT)
        {
            rect.x -= x_val;
            if (rect.x < 0)
            {
                is_move = false;
            }
        }
    }
}
