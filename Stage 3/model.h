#ifndef MODEL_H
#define MODEL_H

#include "../Stage 2/types.h"

typedef struct {
    UINT16 x, y;            /* Position Coordinates, y should be constant, set in the constructor */
    UINT8 l, w;             /* Size of hitbox for collsion detection  */
    UINT8 lives;            /* How many lives this player has */
    int direction;          /* Signed integer, -1, 0, or 1 depending on movement */
    const int bullet_type;  /* Will be 1 */
} Player;

void move_player(Player *player);

typedef struct {
    UINT16 x, y;            /* Position Coordinates */
    UINT8 l, w;             /* Size of hitbox for collision detection */
    int score;              /* Score awarded to Player */
    int alive;              /* To be used as a boolean marker 0 = true, -1 = false */ 
    /* Add bullet fire timing somewhere */
} Alien;

void alien_direc_change(Aliens *alien_arr);

void alien_level(Aliens *alien_arr);

typedef struct {
    Alien r1[11];
    Alien r2[11];
    Alien r3[11];
    Alien r4[11];
    Alien r5[11];
    
    UINT8 totalAliens;
    int direction;          /* -1 or 1 depending on direction of movement */
    const int bullet_type;  /* Will be -1 */
} Aliens;

typedef struct {
    UINT16 x, y;        /* x coordinate should be set and not changed when the object is created */
    UINT8 l, w;         /* Hitbox */
    int y_direction;    /* -1 or 1, moving down or up respectively */
} Bullet;

int move_bullet(Model *model, Bullet *bullet);
}

typedef struct {
    UINT16 score;       /* Score number */
    UINT16 x, y;        /* Position of score sign */
} Score;

typedef struct {
    Player player;
    Aliens aliens;
    Score score;
    UINT16 lowbound_x, lowbound_y, highbound_x, highbound_y; /* Bounds of play area */
} Model;

#endif