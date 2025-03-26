#include "space.h"

extern void clear_screen(UINT32 base);

UINT8 preBuffer[32255];

int main() {
    void *base = Physbase();
    void *active = base;
    void *inactive = (void *)(((UINT32)preBuffer + 255) & 0xFFFFFF00L);

    Model model = {
        { 288, 336, 32, 32, 3, 0, 1 },
        {
            { /* r1 */
                { 0, 32, 32, 32, 150, 1},
                {32, 32, 32, 32, 150, 1},
                {64, 32, 32, 32, 150, 1},
                {96, 32, 32, 32, 150, 1},
                {128, 32, 32, 32, 150, 1},
                {160, 32, 32, 32, 150, 1},
                {192, 32, 32, 32, 150, 1},
                {224, 32, 32, 32, 150, 1},
                {256, 32, 32, 32, 150, 1}
            }, 
            { /* r2 */
                {0, 64, 32, 32, 125, 1},
                {32, 64, 32, 32, 125, 1},
                {64, 64, 32, 32, 125, 1},
                {96, 64, 32, 32, 125, 1},
                {128, 64, 32, 32, 125, 1},
                {160, 64, 32, 32, 125, 1},
                {192, 64, 32, 32, 125, 1},
                {224, 64, 32, 32, 125, 1},
                {256, 64, 32, 32, 125, 1}
            },
            { /* r3 */
                {0, 96, 32, 32, 100, 1},
                {32, 96, 32, 32, 100, 1},
                {64, 96, 32, 32, 100, 1},
                {96, 96, 32, 32, 100, 1},
                {128, 96, 32, 32, 100, 1},
                {160, 96, 32, 32, 100, 1},
                {192, 96, 32, 32, 100, 1},
                {224, 96, 32, 32, 100, 1},
                {256, 96, 32, 32, 100, 1}
            },
            { /* r4 */
                {0, 128, 32, 32, 75, 1},
                {32, 128, 32, 32, 75, 1},
                {64, 128, 32, 32, 75, 1},
                {96, 128, 32, 32, 75, 1},
                {128, 128, 32, 32, 75, 1},
                {160, 128, 32, 32, 75, 1},
                {192, 128, 32, 32, 75, 1},
                {224, 128, 32, 32, 75, 1},
                {256, 128, 32, 32, 75, 1}
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
                {256, 160, 32, 32, 50, 1}
            },
            45,
            8,
            -1,
            1
        },
        { 0, 544, 8},
        0, 0, 630, 400,
        32, 32,
        8,
        4,
        {
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0}
        },
        0,0
    };
    int f = 0;
    int note = 0;
    int temp;
    UINT32 timeStart, timeNow, timeElapsed, timeBefore;

    /* Line below clears screen from cursor and mouse */
    printf("\033E\033f\n");

    timeStart = getTime();

    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    render(&model, active, f);
    
    start_music();
    note = 1;

    while (!model.quit) {
        timeNow = getTime();
        timeElapsed = timeNow - timeStart;

        asyncHandle(&model);
        
        if(timeElapsed > 0){
            syncHandle(&model, timeElapsed);
            
            if((timeElapsed & 0x7F) > 122) { 
                f++;
            }
        }

        clear_screen((UINT32)inactive);

        render(&model, inactive, f);
        swapBuffers(&active, &inactive);

        temp = update_music(timeElapsed, timeBefore, note);
        if (temp == 1) {        
            timeBefore = timeElapsed;
            note++;
            if (note == 48) {
                note = 0;
            }
        }
    }

    stop_sound();

    /* Clear both buffers when done game */
    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);
    /* Set base back */
    Setscreen(-1, base, -1);
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
        case 's':
            async_shoot(model, 0);
            break;
        /* temp case below to see hearts deplete */
        case 'k':
            model->player.lives -= 1;
            break;
    }
}

void syncHandle(Model *model, UINT32 timeElapsed) {
    /* Update aliens based on clock cycle, perhaps double buffer can be done every 1/2th cycle */
    /* Essentially check if elapsed time % 128 == 0 */
    /* change bitmask to change movement time, preferrably a power of 2 for efficiency */
    int game_state;
    if((timeElapsed & 0x7F) > 122) { 
        game_state = update_aliens(model);
        if (game_state == -1) {
            model->quit = 1;
        }
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

void swapBuffers (void **active, void **inactive) {
    void *temp = *active;
    *active = *inactive;
    *inactive = temp;
    Setscreen(-1, *active, -1);
    Vsync();
}

UINT32 getTime() {
    UINT32 *timer = (UINT32 *)0x462;
    UINT32 currTime;
    UINT32 oldSsp;

    oldSsp = Super(0);
    currTime = *timer;
    Super(oldSsp);

    return currTime;
}
