#include "space.h"

extern void clear_screen(UINT32 base);
extern void set_video_base(UINT16 *address);

UINT8 preBuffer[32255];

int main() {
    int play = 0;

    while (1) {
        play = title();
        if (play == 1) {
            break;
        }
        space();
    }
    
    return 0;
}

void space() {
    void *base = get_video_base();
    void *active = base;
    void *inactive = (void *)(((UINT32)preBuffer + 255) & 0xFFFFFF00L);

    Model model = {
        { 288, 336, 32, 32, 3, 0, 1},
        {
            { /* Aliens being updated throughout gameplay */
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
                    {0, 64, 32, 32, 100, 1},
                    {32, 64, 32, 32, 100, 1},
                    {64, 64, 32, 32, 100, 1},
                    {96, 64, 32, 32, 100, 1},
                    {128, 64, 32, 32, 100, 1},
                    {160, 64, 32, 32, 100, 1},
                    {192, 64, 32, 32, 100, 1},
                    {224, 64, 32, 32, 100, 1},
                    {256, 64, 32, 32, 100, 1}
                },
                { /* r3 */
                    {0, 96, 32, 32, 75, 1},
                    {32, 96, 32, 32, 75, 1},
                    {64, 96, 32, 32, 75, 1},
                    {96, 96, 32, 32, 75, 1},
                    {128, 96, 32, 32, 75, 1},
                    {160, 96, 32, 32, 75, 1},
                    {192, 96, 32, 32, 75, 1},
                    {224, 96, 32, 32, 75, 1},
                    {256, 96, 32, 32, 75, 1}
                },
                { /* r4 */
                    {0, 128, 32, 32, 50, 1},
                    {32, 128, 32, 32, 50, 1},
                    {64, 128, 32, 32, 50, 1},
                    {96, 128, 32, 32, 50, 1},
                    {128, 128, 32, 32, 50, 1},
                    {160, 128, 32, 32, 50, 1},
                    {192, 128, 32, 32, 50, 1},
                    {224, 128, 32, 32, 50, 1},
                    {256, 128, 32, 32, 50, 1}
                },
                { /* r5 */
                    {0, 160, 32, 32, 25, 1},
                    {32, 160, 32, 32, 25, 1},
                    {64, 160, 32, 32, 25, 1},
                    {96, 160, 32, 32, 25, 1},
                    {128, 160, 32, 32, 25, 1},
                    {160, 160, 32, 32, 25, 1},
                    {192, 160, 32, 32, 25, 1},
                    {224, 160, 32, 32, 25, 1},
                    {256, 160, 32, 32, 25, 1}
                }
            },
            { /* Original alien positions to restore active aliens */
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
                    {0, 64, 32, 32, 100, 1},
                    {32, 64, 32, 32, 100, 1},
                    {64, 64, 32, 32, 100, 1},
                    {96, 64, 32, 32, 100, 1},
                    {128, 64, 32, 32, 100, 1},
                    {160, 64, 32, 32, 100, 1},
                    {192, 64, 32, 32, 100, 1},
                    {224, 64, 32, 32, 100, 1},
                    {256, 64, 32, 32, 100, 1}
                },
                { /* r3 */
                    {0, 96, 32, 32, 75, 1},
                    {32, 96, 32, 32, 75, 1},
                    {64, 96, 32, 32, 75, 1},
                    {96, 96, 32, 32, 75, 1},
                    {128, 96, 32, 32, 75, 1},
                    {160, 96, 32, 32, 75, 1},
                    {192, 96, 32, 32, 75, 1},
                    {224, 96, 32, 32, 75, 1},
                    {256, 96, 32, 32, 75, 1}
                },
                { /* r4 */
                    {0, 128, 32, 32, 50, 1},
                    {32, 128, 32, 32, 50, 1},
                    {64, 128, 32, 32, 50, 1},
                    {96, 128, 32, 32, 50, 1},
                    {128, 128, 32, 32, 50, 1},
                    {160, 128, 32, 32, 50, 1},
                    {192, 128, 32, 32, 50, 1},
                    {224, 128, 32, 32, 50, 1},
                    {256, 128, 32, 32, 50, 1}
                },
                { /* r5 */
                    {0, 160, 32, 32, 25, 1},
                    {32, 160, 32, 32, 25, 1},
                    {64, 160, 32, 32, 25, 1},
                    {96, 160, 32, 32, 25, 1},
                    {128, 160, 32, 32, 25, 1},
                    {160, 160, 32, 32, 25, 1},
                    {192, 160, 32, 32, 25, 1},
                    {224, 160, 32, 32, 25, 1},
                    {256, 160, 32, 32, 25, 1}
                }
            },
            45, 8, -1, 1, 4, 8, 0,
            {4,4,4,4,4,4,4,4,4}
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
    int alienInterval = 75;
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

        if (timeElapsed > alienInterval) {
            syncHandle(&model, timeElapsed);
            f++;
            timeStart = timeNow;
        }

        syncBullets(&model);
        
        clear_screen((UINT32)inactive);

        render(&model, inactive, f);
        swapBuffers(&active, &inactive);

        temp = update_music(timeNow, timeBefore, note);
        if (temp == 1) {        
            timeBefore = timeNow;
            note++;
            if (note == 48) {
                note = 0;
            }
        }

        /* Speeds up aliens after they reach a certain point vertically */
        /* For some reason if below is abstracted into a function, speed no longer changes */
        if (model.aliens.array[model.aliens.lowest_alive][0].y > 150) {
            alienInterval = 40;
        }
        if (model.aliens.array[model.aliens.lowest_alive][0].y > 200) {
            alienInterval = 25;
        }
        if (model.aliens.array[model.aliens.lowest_alive][0].y > 250) {
            alienInterval = 10;
        }
    }

    stop_sound();
    play_game_over();

    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);
    set_video_base((UINT16 *)base);
}

int title() {
    UINT16 *base = get_video_base();

    /* printf clears screen from cursor and mouse */
    printf("\033E\033f\n");

    clear_screen((UINT32)base);
    render_title((UINT32 *)base);

    while (1) {
        char ch = keystroke();
        switch (ch) {
            case 's':
                return 0; /* Start game */
            case 'q':
                clear_screen((UINT32)base);
                return 1; /* Quit game */     
        }
    }
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
            async_shoot(model, 0);
            break;
    }
}

void syncHandle(Model *model, UINT32 timeElapsed) {
    /* Update aliens based on clock cycle, perhaps double buffer can be done every 1/2th cycle */
    /* Essentially check if elapsed time % 128 == 0 */
    /* change bitmask to change movement time, preferrably a power of 2 for efficiency */
    int game_state; 
    game_state = update_aliens(model);
    aliens_shoot(model);
    if (game_state == -1) {
        model->quit = 1;
    }
    
    /* Check for endgame */
    if (check_endgame(model)) {
        model->quit = 1;
    }
}

void syncBullets(Model *model) {
    if (model->active_count > 0) {
        update_bullets(model);
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