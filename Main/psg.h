#ifndef PSG_H
#define PSG_H

#include "TYPES.H"

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
    B,
    NUM_TONES
} Note;

const UINT16 noteTunings[36][3] = {
    /* 0x 0 C F F, C = Coarse, F = Fine. */

    /*                 3         4          5      */
    /* C */         {{0x3BE}, {0x1DC},  {0xEF}},
    /* C_SHARP */   {{0x387}, {0x1C3},  {0xE1}},
    /* D */         {{0x354}, {0x1A9},  {0xD5}},
    /* D_SHARP */   {{0x324}, {0x192},  {0xC8}},
    /* E */         {{0x2F8}, {0x17B},  {0xBD}},
    /* F */         {{0x2CC}, {0x164},  {0xB2}},
    /* F_SHARP */   {{0x2A5}, {0x150},  {0xA8}},
    /* G */         {{0x27E}, {0x13E},  {0x9F}},
    /* G_SHARP */   {{0x25A}, {0x12D},  {0x96}},
    /* A */         {{0x239}, {0x11B},  {0x8E}},
    /* A_SHARP */   {{0x219}, {0x10A},  {0x85}},
    /* B */         {{0x1FA}, {0x0FD},  {0x7E}},
};


void write_psg(int reg, UINT8 val);

void set_tone(int channel, int tuning);

void set_volume(int channel, int volume);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

#endif