#ifndef TIMER_H_
#define TIMER_H_

class Timer
{
public:
    Timer();
    ~Timer();

    void start();
    void stop();
    void paused();
    void unpaused();

    int get_tick();

    bool is_Started();
    bool is_Paused();
private:
    int start_tick;
    int paused_tick;

    bool is_paused;
    bool is_started;
};

#endif // TIMER_H_
