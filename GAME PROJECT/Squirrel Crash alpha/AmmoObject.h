#ifndef AMMO_OBJECT_H_
#define AMMO_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class AmmoObject : public BaseObject
{
public:
    AmmoObject();
    ~AmmoObject();

    enum AmmoDir
    {
        DIR_RIGHT = 20,
        DIR_LEFT = 21
    };
    void set_x_val(const int& xVal) { x_val = xVal; }
    void set_y_val(const int& yVal) { y_val = yVal; }
    int get_x_val() const { return x_val; }
    int get_y_val() const { return y_val; }

    void set_is_move(const bool& isMove) { is_move = isMove; }
    bool get_is_move() const { return is_move; }

    void set_ammo_dir(const int& ammoDir) { ammo_dir = ammoDir;}
    int get_ammo_dir() const { return ammo_dir; }

    void HandleMove(const int& x_border, const int& y_border);

private:
    int x_val;
    int y_val;
    bool is_move;
    int ammo_dir;
};

#endif // AMMO_OBJECT_H_
