#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
#include "AmmoObject.h"
#include <vector>

#define THREAT_SIZE 100
#define THREAT_AMMO 40
using namespace std;

class ThreatObject : public BaseObject
{
public:
    ThreatObject();
    ~ThreatObject();

    void HandleMove(const int& x_border, const int& y_border);
    void HandleInputAction(SDL_Event events);

    void set_x_val(const int& xVal) { x_val = xVal; }
    int get_x_val() const { return x_val; }
    void set_y_val(const int& yVal) { y_val = yVal; }
    int get_y_val() const { return y_val; }

    void Reset(const int& x_border, const int& y_border);

private:
    int x_val;
    int y_val;
};

#endif // THREAT_OBJECT_H_
