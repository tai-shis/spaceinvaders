#include "music.h"

typedef enum{
    C = 0,
    C_SHARP,
    D,
    D_SHARP,
    E,
    F,
    F_SHARP,
    G,
    G_SHARP,
    A,
    A_SHARP,
    B
} Note;

const UINT16 noteTunings[12][3] = {
    /* 0x 0 C F F, C = Coarse, F = Fine. */

    /*                 3th        4th        5th */
    /* C */         {{0x03BE}, {0x01DC},  {0x00EF}},
    /* C_SHARP */   {{0x0387}, {0x01C3},  {0x00E1}},
    /* D */         {{0x0354}, {0x01A9},  {0x00D5}},
    /* D_SHARP */   {{0x0324}, {0x0192},  {0x00C8}},
    /* E */         {{0x02F8}, {0x017B},  {0x00BD}},
    /* F */         {{0x02CC}, {0x0164},  {0x00B2}},
    /* F_SHARP */   {{0x02A5}, {0x0150},  {0x00A8}},
    /* G */         {{0x027E}, {0x013E},  {0x009F}},
    /* G_SHARP */   {{0x025A}, {0x012D},  {0x0096}},
    /* A */         {{0x0239}, {0x011B},  {0x008E}},
    /* A_SHARP */   {{0x0219}, {0x010A},  {0x0085}},
    /* B */         {{0x01FA}, {0x00FD},  {0x007E}},
};

UINT16 song_a[48][2] = {
    /* Fallen Down from undertale */
    {F_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    {C_SHARP, 2},
    {F_SHARP, 2},
    
    {B, 1},
    {A, 1},
    {C_SHARP, 2},
    {C_SHARP, 2},
    {A, 1},
    {B, 1},
    
    {E, 2},
    {D_SHARP, 2},
    {E, 2},
    {F_SHARP, 2},
    {D_SHARP, 2},
    {B, 1},
    
    {F_SHARP, 2},
    {B, 1},
    {F_SHARP, 2},
    {B, 1},
    {F_SHARP, 2},
    {B, 1},
    
    {F_SHARP, 2},
    {A_SHARP, 1},
    {F_SHARP, 2},
    {A_SHARP, 1},
    {G, 2},
    {G, 2},
    
    {F_SHARP, 2},
    {D, 2},
    {F_SHARP, 2},
    {D, 2},
    {E, 2},
    {F_SHARP, 2},
    
    {E, 2},
    {E, 2},
    {D, 2},
    {D, 2},
    {C_SHARP, 2},
    {C_SHARP, 2}
};

void start_music() {

    /* First notes */
    set_tone(0, noteTunings[song_a[0][0]][song_a[0][1]]);
    
    set_volume(0, 0xD);

    enable_channel(0, 1, 0);
    

    /* Disabled for now */
    /*
    set_tone(1, noteTunings[B][1]);
    set_volume(1, 5);
    enable_channel(1, 1, 0);
    */
}

char update_music(UINT32 time_elapsed, UINT32 time_before, int note) {
    

    /* 3/4 Time Signature, updates every 1/8th note */
    if ((time_elapsed - time_before) > 12) {
       set_tone(0, noteTunings[song_a[note][0]][song_a[note][1]]); 
       return 1;
    }

    return 0;
}