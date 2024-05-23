
#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_

#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_audio.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

/// Screen
const int FRAME_PER_SECOND = 50;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 255;

const int THREAT_NUM = 4;
/* Game's Tile Map Sizes
#define TILE_SIZE 80
#define MAX_MAP_X 400
#define MAX_MAP_Y 10

typedef struct Map{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    char* file_name;
};
*/

struct Input
{
    int left;
    int right;
    int up;
    int down;
    // int run;
};

bool CheckCollision(const SDL_Rect& a, const SDL_Rect& b);
int ShowMenu(SDL_Renderer* screen, TTF_Font* font, TTF_Font* title_font);
#endif // common_func_h_
