#ifndef PLAYER_OBJECT_H_
#define PLAYER_OBJECT_H_

#include <bits/stdc++.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "AmmoObject.h"

using namespace std;
#define CHAR_SIZE 100

class PlayerObject : public BaseObject
{
public:
    PlayerObject();
    ~PlayerObject();

    enum WalkType
    {
        Walk_Right = 0,
        Walk_Left = 1
    };

    bool LoadImg(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void SetClip();
    void HandleMove();

    void set_ammo_list(vector<AmmoObject*> ammo_list)
    {
        p_ammo_list = ammo_list;
    }
    vector<AmmoObject*> get_ammo_list() const {return p_ammo_list;}
    void HandleAmmo(SDL_Renderer* des);
    void RemoveAmmo(const int& idx);
private:
    /// Ammo
    vector<AmmoObject*> p_ammo_list;

    /// Player's position values
    float x_val;
    float y_val;
    float x_pos;
    float y_pos;

    int frame_width;
    int frame_height;

    SDL_Rect frame_clip[1];
    /// 8 FPS
    Input input_type;
    int frame;
    int status; // status: player facing left or right
};
#endif // PLAYER_OBJECT_H_
