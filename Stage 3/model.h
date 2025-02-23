#ifndef MODEL_H
#define MODEL_H

#include "types.h"

typedef struct Player {
    UINT16 x, y;            /* Position Coordinates, y should be constant, set in the constructor */
    UINT8 l, w;             /* Size of hitbox for collsion detection  */
    UINT8 lives;            /* How many lives this player has */
    int delta_x;          /* Signed integer, -1, 0, or 1 depending on movement */
    int b_type;  /* Will be 1 */
} Player;

typedef struct Alien {
    UINT16 x, y;            /* Position Coordinates */
    UINT8 l, w;             /* Size of hitbox for collision detection */
    int score;              /* Score awarded to Player */
    int alive;              /* To be used as a boolean marker 0 = true, -1 = false */ 
    /* Add bullet fire timing somewhere */
} Alien;

typedef struct Aliens{
    Alien r1[11];
    Alien r2[11];
    Alien r3[11];
    Alien r4[11];
    Alien r5[11];
    UINT8 totalAliens;
    int delta_x;          /* -1(left) or 1(right) depending on direction of movement */
    int b_type;  /* Will be -1 */
} Aliens;

typedef struct Bullet {
    UINT16 x, y;        /* x coordinate should be set and not changed when the object is created */
    UINT8 l, w;         /* Hitbox */
    int y_direction;    /* -1 or 1, moving down or up respectively */
} Bullet;

typedef struct Score {
    UINT16 score;       /* Score number */
    UINT16 x, y;        /* Position of score sign */
} Score;

typedef struct Model {
    Player player;
    Aliens aliens;
    Score score;
    UINT16 low_x, low_y, high_x, high_y; /* Bounds of play area. highbounds should be bound - alien_w */ 
    UINT8 alien_l, alien_w;    /* Used for movement and collision detection */      
    int alien_dx;
    int bullet_dy;
} Model;

void move_player(Model *model, Player *player);

void alien_direc_change(Model *model, Aliens *alien_arr);

int move_aliens(Model *model, Aliens *aliens);

int lower_aliens(Model *model, Aliens *alien_arr);

void destroy_alien(Alien alien, Score curr_score);

int move_bullet(Model *model, Bullet *bullet);

void add_score (int score_to_add, Score curr_score);

void update_score(Score *score);

#endif