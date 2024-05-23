#include "ExplosionObject.h"

ExplosionObject::ExplosionObject()
{
    frame_width = 0;
    frame_height = 0;
    frame = 0;
}

ExplosionObject::~ExplosionObject()
{

}

bool ExplosionObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path,screen);
    if (ret)
    {
        frame_width = rect.w / FRAME_EXP_NUM;
        frame_height = rect.h;
    }

    return ret;
}
void ExplosionObject::set_clip()
{
    if (frame_width>0 && frame_height >0)
    {
        frame_clip[0].x = 0;
        frame_clip[0].y = 0;
        frame_clip[0].w = frame_width;
        frame_clip[0].h = frame_height;

        frame_clip[1].x = frame_width;
        frame_clip[1].y = 0;
        frame_clip[1].w = frame_width;
        frame_clip[1].h = frame_height;

        frame_clip[2].x = 2*frame_width;
        frame_clip[2].y = 0;
        frame_clip[2].w = frame_width;
        frame_clip[2].h = frame_height;

        frame_clip[3].x = 3*frame_width;
        frame_clip[3].y = 0;
        frame_clip[3].w = frame_width;
        frame_clip[3].h = frame_height;
    }
}

void ExplosionObject::Show(SDL_Renderer* screen)
{
    SDL_Rect* current_clip = &frame_clip[frame];
    SDL_Rect render_quad = {rect.x, rect.y, frame_width, frame_height};
    if (current_clip != NULL)
    {
        render_quad.w = current_clip->w;
        render_quad.h = current_clip->h;
    }

    SDL_RenderCopy(screen, p_object, current_clip, &render_quad);
}
