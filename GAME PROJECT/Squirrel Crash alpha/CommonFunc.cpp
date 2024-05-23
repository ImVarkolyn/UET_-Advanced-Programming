#include "CommonFunc.h"
#include "TextObject.h"

bool CheckCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    int left_a = a.x;
    int right_a = a.x + a.w;
    int top_a = a.y;
    int bottom_a = a.y + a.h;

    int left_b = b.x;
    int right_b = b.x + b.w;
    int top_b = b.y;
    int bottom_b = b.y + b.h;

    if (left_a < right_b && right_a > left_b && top_a < bottom_b && bottom_a > top_b)
    {
        return true;
    }
    return false;
}

int ShowMenu(SDL_Renderer* screen, TTF_Font* font, TTF_Font* title_font)
{
    const int menu_items = 2;
    const char* menu_texts[menu_items] = { "Play", "Exit" };
    SDL_Rect menu_pos[menu_items];
    TextObject menu[menu_items];

    // Set menu position and size
    for (int i = 0; i < menu_items; i++)
    {
        menu[i].SetText(menu_texts[i]);
        menu[i].LoadFromRenderText(font, screen);
        menu_pos[i].x = SCREEN_WIDTH / 2 - (menu[i].GetWidth() * 5) / 2;
        menu_pos[i].y = SCREEN_HEIGHT / 2 + i * 100;
        menu_pos[i].w = menu[i].GetWidth() * 5;
        menu_pos[i].h = menu[i].GetHeight() * 5;
    }

    int selected = 0;
    bool selected_menu = false;
    SDL_Event event;

    // Load menu background image
    SDL_Surface* menu_background = IMG_Load("img//background.jpg");
    SDL_Texture* menu_background_texture = SDL_CreateTextureFromSurface(screen, menu_background);
    SDL_FreeSurface(menu_background);

    // Load game title
    TextObject game_title;
    game_title.SetText("SQUIRREL CRASH");
    game_title.SetColor(TextObject::BLACK_TEXT);
    game_title.LoadFromRenderText(title_font, screen);
    SDL_Rect title_pos;
    title_pos.x = SCREEN_WIDTH / 2 - game_title.GetWidth() / 2;
    title_pos.y = 50;
    title_pos.w = game_title.GetWidth();
    title_pos.h = game_title.GetHeight();

    while (!selected_menu)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return 1;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    selected--;
                    if (selected < 0)
                    {
                        selected = menu_items - 1;
                    }
                    break;
                case SDLK_DOWN:
                    selected++;
                    if (selected >= menu_items)
                    {
                        selected = 0;
                    }
                    break;
                case SDLK_RETURN:
                    selected_menu = true;
                    break;
                default:
                    break;
                }
            }
        }


        SDL_RenderClear(screen);
        SDL_RenderCopy(screen, menu_background_texture, NULL, NULL);


        game_title.RenderText(screen, title_pos.x, title_pos.y);


        for (int i = 0; i < menu_items; i++)
        {
            if (i == selected)
            {
                menu[i].SetColor(TextObject::RED_TEXT);
            }
            else
            {
                menu[i].SetColor(TextObject::WHITE_TEXT);
            }
            menu[i].LoadFromRenderText(font, screen);
            menu[i].RenderText(screen, menu_pos[i].x, menu_pos[i].y, NULL, 0.0, NULL, SDL_FLIP_NONE, menu_pos[i].w, menu_pos[i].h);
        }

        SDL_RenderPresent(screen);
    }

    SDL_DestroyTexture(menu_background_texture);

    return selected;
}
