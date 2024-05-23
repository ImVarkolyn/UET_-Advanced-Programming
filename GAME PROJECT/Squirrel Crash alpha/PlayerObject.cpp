#include "PlayerObject.h"

PlayerObject::PlayerObject()
{
    frame = 0;
    x_pos = 0;
    y_pos = 0;
    x_val = 0;
    y_val = 0;
    frame_width = 0;
    frame_height = 0;
    status = -1;
    input_type.left = 0;
    input_type.right = 0;
    input_type.down = 0;
    input_type.up = 0;
}

PlayerObject::~PlayerObject()
{

}

bool PlayerObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path, screen);

    if (ret == true)
    {
        frame_width = rect.w / 1;
        frame_height = rect.h;
    }

    return ret;
}

void PlayerObject::SetClip()
{
    if (frame_width > 0 && frame_height > 0)
    {
        for (int i = 0; i < 1; ++i)
        {
            frame_clip[i].x = i * frame_width;
            frame_clip[i].y = 0;
            frame_clip[i].w = frame_width;
            frame_clip[i].h = frame_height;
        }
    }
}

void PlayerObject::Show(SDL_Renderer* des)
{
    if (status == Walk_Left)
    {
        LoadImg("img//char_left.jpg", des);
    }
    else
    {
        LoadImg("img//char_right.jpg", des);
    }

    if (input_type.left == 1 || input_type.right == 1 || input_type.up == 1 || input_type.down == 1)
    {
        frame++;
    }
    else
    {
        frame = 0;
    }

    if (frame >= 1)
    {
        frame = 0;
    }

    rect.x = x_pos;
    rect.y = y_pos;

    SDL_Rect* current_clip = &frame_clip[frame];
    SDL_Rect renderQuad = { rect.x, rect.y, frame_width, frame_height };

    SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
}

void PlayerObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    /// Key events
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            status = Walk_Right;
            input_type.right = 1;
            input_type.left = 0;
            x_val = CHAR_SIZE / 10;
            break;
        case SDLK_LEFT:
            status = Walk_Left;
            input_type.left = 1;
            input_type.right = 0;
            x_val = -CHAR_SIZE / 10;
            break;
        case SDLK_UP:
            input_type.up = 1;
            y_val = -CHAR_SIZE / 10;
            break;
        case SDLK_DOWN:
            input_type.down = 1;
            y_val = CHAR_SIZE / 10;
            break;
        default:
            break;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            input_type.right = 0;
            x_val = 0;
            break;
        case SDLK_LEFT:
            input_type.left = 0;
            x_val = 0;
            break;
        case SDLK_UP:
            input_type.up = 0;
            y_val = 0;
            break;
        case SDLK_DOWN:
            input_type.down = 0;
            y_val = 0;
            break;
        default:
            break;
        }
    }

    /// Mouse events
    if(events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            AmmoObject* p_ammo = new AmmoObject();
            p_ammo->LoadImg("img//ammo.png",screen);
            if(status == Walk_Left)
            {
                p_ammo->set_ammo_dir(AmmoObject::DIR_LEFT);
                p_ammo->SetRect(this->rect.x, rect.y + frame_height - 60);
            }
            else if (status == Walk_Right)
            {
                p_ammo->set_ammo_dir(AmmoObject::DIR_RIGHT);
                p_ammo->SetRect(this->rect.x + frame_width - 60, rect.y + frame_height - 60);

            }
            p_ammo->set_x_val(10);
            p_ammo->set_is_move(true);

            p_ammo_list.push_back(p_ammo);
        }
    }
}

void PlayerObject::HandleAmmo(SDL_Renderer* des)
{
    for (int i=0; i<p_ammo_list.size();i++)
    {
        AmmoObject* p_ammo = p_ammo_list.at(i);
        if (p_ammo != NULL)
        {
            if (p_ammo->get_is_move() == true)
            {
                p_ammo->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_ammo->Render(des);
            }
            else
            {
                p_ammo_list.erase(p_ammo_list.begin()+i);
                if(p_ammo != NULL)
                {
                    delete p_ammo;
                    p_ammo = NULL;
                }

            }
        }
    }
}

void PlayerObject::HandleMove()
{
    x_pos += x_val;
    if (x_pos < 0 || x_pos + frame_width > SCREEN_WIDTH)
    {
        x_pos -= x_val;
    }

    y_pos += y_val;
    if (y_pos < 0 || y_pos + frame_height > SCREEN_HEIGHT)
    {
        y_pos -= y_val;
    }
}

void PlayerObject::RemoveAmmo(const int& idx)
{
    for (int i=0; i< p_ammo_list.size(); i++)
    {
        if (idx<p_ammo_list.size())
        {
            AmmoObject* p_ammo = p_ammo_list.at(i);
            p_ammo_list.erase(p_ammo_list.begin()+idx);

            if (p_ammo != NULL)
            {
                delete p_ammo;
                p_ammo = NULL;
            }
        }
    }
}
