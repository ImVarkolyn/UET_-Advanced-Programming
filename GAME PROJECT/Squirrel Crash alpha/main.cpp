#include <bits/stdc++.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "PlayerObject.h"
#include "ThreatObject.h"
#include "AmmoObject.h"
#include "ExplosionObject.h"
#include "Timer.h"
#include "TextObject.h"

using namespace std;

BaseObject g_background;
TTF_Font* g_font = NULL;
TTF_Font* g_title_font = NULL;

bool InitSDL()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("SQUIRREL CRASH",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (g_window == NULL)
        success = false;
    else {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
                success = false;
            if (TTF_Init() == -1)
                success = false;
            g_font = TTF_OpenFont("font//ThaleahFat.ttf", 20);
            if (g_font == NULL)
                success = false;
        }
    }

    return success;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img//map_resize.jpg", g_screen);
    if (ret == false)
    {
        ret = g_background.LoadImg("img//map_resize.png", g_screen);
        if (ret == false)
            return false;
    }

    return true;
}

void quitSDL()
{
    g_background.Free();
    if (g_font != NULL)
    {
        TTF_CloseFont(g_font);
        g_font = NULL;
    }

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void ShowExplosion(SDL_Renderer* screen, ExplosionObject& exp, int x, int y)
{
    int frame_exp_width = exp.get_frame_width();
    int frame_exp_height = exp.get_frame_height();

    for (int ex = 0; ex < FRAME_EXP_NUM; ex++)
    {
        int x_pos = x - frame_exp_width * 0.5;
        int y_pos = y - frame_exp_height * 0.5;

        exp.set_frame(ex);
        exp.SetRect(x_pos, y_pos);
        exp.Show(screen);
        SDL_RenderPresent(screen);
    }
}

/// MAIN!
int main(int argc, char* argv[])
{
    Timer fps_timer;
    if (InitSDL() == false)
        return -1;

    if (LoadBackground() == false)
        return -1;

    /// Show menu
    int menu_result = ShowMenu(g_screen, g_font, g_title_font);
    if (menu_result == 1) // Exit selected
    {
        quitSDL();
        return 0;
    }

    /// Init Player
    PlayerObject p_player;
    p_player.LoadImg("img//char_right.jpg", g_screen);
    p_player.SetClip();
    p_player.SetRect(0, 0);

    /// Init Explosion for threat
    ExplosionObject exp_threat;
    bool tRet = exp_threat.LoadImg("img//exp_main.png", g_screen);
    if (!tRet)
        return -1;
    exp_threat.set_clip();

    /// Init Explosion for player
    ExplosionObject exp_player;
    tRet = exp_player.LoadImg("img//exp_main.png", g_screen);
    if (!tRet)
        return -1;
    exp_player.set_clip();

    /// Init Threats
    ThreatObject* p_threats = new ThreatObject[THREAT_NUM];
    for (int t = 0; t < THREAT_NUM; t++)
    {
        ThreatObject* p_threat = p_threats + t;
        if (p_threat)
        {
            if (!p_threat->LoadImg("img//threat_left.png", g_screen))
            {
                delete[] p_threats;
                quitSDL();
                return -1;
            }

            // Random starting positions
            int rand_y = rand() % (SCREEN_HEIGHT - THREAT_SIZE);
            p_threat->SetRect(SCREEN_WIDTH + (t + 1) * 400, rand_y);
            p_threat->set_x_val(10);  // threat speed
        }
    }

    int lives = 3;
    int player_score = 0;

    /// Init TextObjects
    TextObject lives_text;
    lives_text.SetColor(TextObject::WHITE_TEXT);

    TextObject score_text;
    score_text.SetColor(TextObject::WHITE_TEXT);

    TextObject time_text;
    time_text.SetColor(TextObject::WHITE_TEXT);

    bool isQuit = false;
    while (!isQuit)
    {
        fps_timer.start();
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                isQuit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        // Player
        p_player.HandleMove();
        p_player.HandleAmmo(g_screen);
        p_player.Show(g_screen);

        // lives text
        lives_text.SetText("Lives: " + to_string(lives));
        lives_text.LoadFromRenderText(g_font, g_screen);
        lives_text.RenderText(g_screen, 10, 10);

        // score text
        score_text.SetText("Score: " + to_string(player_score));
        score_text.LoadFromRenderText(g_font, g_screen);
        score_text.RenderText(g_screen, 210, 10);

        // Threats
        for (int j = 0; j < THREAT_NUM; j++)
        {
            ThreatObject* p_threat = p_threats + j;
            if (p_threat)
            {
                p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                p_threat->Render(g_screen);

                // Check collision between player and threat
                bool is_collide = CheckCollision(p_player.GetRect(), p_threat->GetRect());
                if (is_collide)
                {
                    // Show explosion when player collides with threat
                    ShowExplosion(g_screen, exp_player, p_player.GetRect().x + 40, p_player.GetRect().y + 40);
                    lives--;
                    p_threat->Reset(SCREEN_WIDTH + (j + 1) * 400, SCREEN_WIDTH);
                    SDL_Delay(1000); // Respawn time
                    if (lives == 0)
                    {
                        if (MessageBox(NULL, "GAME OVER! GG", "Info", MB_OK) == IDOK)
                        {
                            delete[] p_threats;
                            quitSDL();
                            return 0;
                        }
                    }
                    else
                        p_player.SetRect(0, 0);
                }

                // Check for collision between ammo and threat
                vector<AmmoObject*> ammo_list = p_player.get_ammo_list();
                for (int im = 0; im < ammo_list.size(); im++)
                {
                    AmmoObject* p_ammo = ammo_list.at(im);
                    if (p_ammo != NULL)
                    {
                        bool ret_col = CheckCollision(p_ammo->GetRect(), p_threat->GetRect());
                        if (ret_col)
                        {
                            ShowExplosion(g_screen, exp_threat, p_ammo->GetRect().x, p_ammo->GetRect().y);
                            p_threat->Reset(SCREEN_WIDTH + (j + 1) * 400, SCREEN_WIDTH);
                            p_player.RemoveAmmo(im);
                            player_score++;
                        }
                    }
                }
            }
        }

        // Show game time
        string str_time = "TIME: ";
        Uint32 time_val = SDL_GetTicks() / 1000; // convert ms to s
        Uint32 val_time = 300 - time_val;
        if (val_time <= 0)
        {
            if (MessageBox(NULL, "TIME'S UP! WELL PLAYED", "Info", MB_OK) == IDOK)
            {
                isQuit = true;
                break;
            }
        }
        else
        {
            string str_val = to_string(val_time);
            str_time += str_val;
            time_text.SetText(str_time);
            time_text.LoadFromRenderText(g_font, g_screen);
            time_text.RenderText(g_screen, SCREEN_WIDTH - 200, 15);
        }

        SDL_RenderPresent(g_screen);

        /// Handling FPS
        int real_time = fps_timer.get_tick(); // average real time low => fps high
                 int time_one_frame = 1000 / FRAME_PER_SECOND; // ms not s
        if (real_time < time_one_frame)
        {
            int delay_time = time_one_frame - real_time;
            if (delay_time > 0)
                SDL_Delay(delay_time);
        }
    }

    delete[] p_threats;
    quitSDL();
    return 0;
}

