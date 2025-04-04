#include "music.h"

const UINT16 noteTunings[12][3] = {
    /* Goes note->octave */
    /* Aren't enharmonic equivalents fun? */
    /* My entire childhood of doing music is going to good use */
    {{0x03BE}, {0x01DC},  {0x00EF}}, /* C3 - C5 */ 
    {{0x0387}, {0x01C3},  {0x00E1}}, /* C#3 - C#5*/ /* C# == Db */
    {{0x0354}, {0x01A9},  {0x00D5}}, /* D3 - D5 */ /* D# == Eb */
    {{0x0324}, {0x0192},  {0x00C8}}, /* D#3 - D#5*/ /* G# == Ab */
    {{0x02F8}, {0x017B},  {0x00BD}}, /* E3 - E5 */ /* E# == F */
    {{0x02CC}, {0x0164},  {0x00B2}}, /* F3 - F5*/ 
    {{0x02A5}, {0x0150},  {0x00A8}}, /* F#3 - F#5*/ /* F# == Gb */
    {{0x027E}, {0x013E},  {0x009F}}, /* G3 - G5*/
    {{0x025A}, {0x012D},  {0x0096}}, /* G#3 - G#5*/ /* G# == Ab */
    {{0x0239}, {0x011B},  {0x008E}}, /* A3 - A5*/
    {{0x0219}, {0x010A},  {0x0085}}, /* A#3 - A#5*/ /* A# == Bb */
    {{0x01FA}, {0x00FD},  {0x007E}} /* B3 - B5*/
};

UINT16 song_a[48][2] = {
    /* Fallen Down from undertale */
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
    {C_SHARP, 2},
    
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
    set_tone(0, noteTunings[F_SHARP][2]);
    
    set_volume(0, 0xA);

    enable_channel(0, 1, 0);
    
    /* Disabled for now */
    /*
    set_tone(1, noteTunings[B][1]);
    set_volume(1, 5);
    enable_channel(1, 1, 0);
    */
}

char update_music(UINT32 time_now, UINT32 time_before, int note) {
    /* 3/4 Time Signature, updates every 1/8th note */
    if ((time_now - time_before) > 20) {
       set_tone(0, noteTunings[song_a[note][0]][song_a[note][1]]); 
       return 1;
    }

    return 0;
}