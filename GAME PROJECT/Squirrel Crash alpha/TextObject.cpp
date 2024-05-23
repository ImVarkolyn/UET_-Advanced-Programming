#include "TextObject.h"

TextObject::TextObject()
{
    text_color = {255, 255, 255};
    texture = NULL;
    width = 0;
    height = 0;
}

TextObject::~TextObject()
{
    Free();
}

bool TextObject::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen)
{
    Free();

    SDL_Surface* text_surface = TTF_RenderText_Solid(font, str_val.c_str(), text_color);
    if (text_surface)
    {
        texture = SDL_CreateTextureFromSurface(screen, text_surface);
        if (texture)
        {
            width = text_surface->w;
            height = text_surface->h;
        }
        SDL_FreeSurface(text_surface);
    }

    return texture != NULL;
}

void TextObject::Free()
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void TextObject::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    text_color = {red, green, blue};
}

void TextObject::SetColor(int type)
{
    if (type == RED_TEXT)
    {
        text_color = {255, 0, 0};
    }
    else if (type == WHITE_TEXT)
    {
        text_color = {255, 255, 255};
    }
    else if (type == BLACK_TEXT)
    {
        text_color = {255, 219, 88};
    }
}

void TextObject::RenderText(SDL_Renderer* screen,
                            int xp, int yp,
                            SDL_Rect* clip,
                            double angle,
                            SDL_Point* center,
                            SDL_RendererFlip flip,
                            int width,
                            int height)
{
    SDL_Rect renderQuad = {xp, yp, this->width, this->height};
    if (width != -1 && height != -1)
    {
        renderQuad.w = width;
        renderQuad.h = height;
    }
    else if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(screen, texture, clip, &renderQuad, angle, center, flip);
}
