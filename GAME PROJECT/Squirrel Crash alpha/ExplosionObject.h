#ifndef EXPLOSION_OBJECT_H_
#define EXPLOSION_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

#define FRAME_EXP_NUM 4

class ExplosionObject : public BaseObject
{
public:
    ExplosionObject();
    ~ExplosionObject();

    void set_clip();
    void set_frame(const int& fr) {frame = fr;}
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    int get_frame_width() const {return frame_width;}
    int get_frame_height() const {return frame_height;}
private:
    int frame_width;
    int frame_height;

    int frame;
    SDL_Rect frame_clip[4];
};

#endif // EXPLOSION_OBJECT_H_
