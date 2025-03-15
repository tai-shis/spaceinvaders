#include "game.h"
#include <osbind.h>

extern void clear_screen(UINT32 base);

int main() {
    void *base = Physbase();
    Model model = {
        { 288, 368, 32, 32, 3, 0, 1 },
        {
            { /* r1 */
                { 0, 32, 32, 32, 250, 1},
                {32, 32, 32, 32, 250, 1},
                {64, 32, 32, 32, 250, 1},
                {96, 32, 32, 32, 250, 1},
                {128, 32, 32, 32, 250, 1},
                {160, 32, 32, 32, 250, 1},
                {192, 32, 32, 32, 250, 1},
                {224, 32, 32, 32, 250, 1},
                {256, 32, 32, 32, 250, 1},
                {288, 32, 32, 32, 250, 1},
                {320, 32, 32, 32, 250, 1}
            }, 
            { /* r2 */
                {0, 64, 32, 32, 200, 1},
                {32, 64, 32, 32, 200, 1},
                {64, 64, 32, 32, 200, 1},
                {96, 64, 32, 32, 200, 1},
                {128, 64, 32, 32, 200, 1},
                {160, 64, 32, 32, 200, 1},
                {192, 64, 32, 32, 200, 1},
                {224, 64, 32, 32, 200, 1},
                {256, 64, 32, 32, 200, 1},
                {288, 64, 32, 32, 200, 1},
                {320, 64, 32, 32, 200, 1}
            },
            { /* r3 */
                {0, 96, 32, 32, 150, 1},
                {32, 96, 32, 32, 150, 1},
                {64, 96, 32, 32, 150, 1},
                {96, 96, 32, 32, 150, 1},
                {128, 96, 32, 32, 150, 1},
                {160, 96, 32, 32, 150, 1},
                {192, 96, 32, 32, 150, 1},
                {224, 96, 32, 32, 150, 1},
                {256, 96, 32, 32, 150, 1},
                {288, 96, 32, 32, 150, 1},
                {320, 96, 32, 32, 150, 1}
            },
            { /* r4 */
                {0, 128, 32, 32, 100, 1},
                {32, 128, 32, 32, 100, 1},
                {64, 128, 32, 32, 100, 1},
                {96, 128, 32, 32, 100, 1},
                {128, 128, 32, 32, 100, 1},
                {160, 128, 32, 32, 100, 1},
                {192, 128, 32, 32, 100, 1},
                {224, 128, 32, 32, 100, 1},
                {256, 128, 32, 32, 100, 1},
                {288, 128, 32, 32, 100, 1},
                {320, 128, 32, 32, 100, 1}
            },
            { /* r5 */
                {0, 160, 32, 32, 50, 1},
                {32, 160, 32, 32, 50, 1},
                {64, 160, 32, 32, 50, 1},
                {96, 160, 32, 32, 50, 1},
                {128, 160, 32, 32, 50, 1},
                {160, 160, 32, 32, 50, 1},
                {192, 160, 32, 32, 50, 1},
                {224, 160, 32, 32, 50, 1},
                {256, 160, 32, 32, 50, 1},
                {288, 160, 32, 32, 50, 1},
                {320, 160, 32, 32, 50, 1}
            },
            55,
            8,
            -1,
            1
        },
        { 0, 544, 8},
        0, 0, 630, 400,
        32, 32,
        8,
        1,
        {
            {304, 300, 8, 16, 1}, /* Player bullet */
            {0, 50, 8, 16,-1}, /* Alien bullet */
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        2,0
    };

    UINT32 timeThen, timeNow, timeElapsed;
    timeThen = 0;

    clear_screen((UINT32)base);

    render(&model, base, 0);

    while (!model.quit) {
        /* Get input */
        /* Update model */
        /* Render */
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        asyncHandle(&model);

        if(timeElapsed > 0 ){
            /* Uses time elapsed, time now, and time then probably to handle updates*/
            syncHandle(&model, timeElapsed);
            timeThen = timeNow;
        }
        
        render(&model, base, timeElapsed);
        Vsync();
        /* clear_screen((UINT32)base); */
    }

    /* Clear whole screen when done game */
    clear_screen((UINT32)base);
    return 0;
}

void asyncHandle(Model *model) {
    char ch = keystroke();

    switch (ch) {
        case 'q':
            model->quit = 1;
            break;
        case 'a':
            async_move_player(model, ch);
            break;
        case 'd':
            async_move_player(model, ch);
            break;
        case ' ':
            async_shoot(model, -1);
            break;
        case 27:
            model->quit = 1;    
    }
}

void syncHandle(Model *model, UINT32 timeElapsed) {
    /* Update aliens based on clock cycle, perhaps double buffer can be done every 1/2th cycle */
    /* Essentially check if elapsed time % 128 == 0 */
    /* change bitmask to change movement time, preferrably a power of 2 for efficiency */
    if((timeElapsed & 0x7F) == 0) { 
        update_aliens(model); 
        model->aliens.render = 1;
    }
    /* Update bullets */
    if (model->active_count > 0) {
        update_bullets(model);
    }

    /* Check for endgame */
    if (check_endgame(model)) {
        model->quit = 1;
    }
}

UINT32 getTime() {
    long *timer = (long *)0x462;
    long currTime;
    long oldSsp;

    oldSsp = Super(0);
    currTime = *timer;
    Super(oldSsp);

    return (UINT32)currTime;
}
