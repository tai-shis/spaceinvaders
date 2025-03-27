/**
    * @authors Harinder Punia & Tai Shishiba
    * @file model.h
    * @brief Header file for model.c
    * @date 2025-02-12
    * @details All types of data structures for the game, like player, alien, bullet, score, and model (game environment) are defined here.
    *          Functions for moving player, aliens, bullets, updating score, collsion detection, and other game logic are also defined here.
*/

#ifndef MODEL_H
#define MODEL_H

#include "types.h"
#include "effects.h"

typedef struct Player {
    UINT16 x, y;            /* Position Coordinates, y should be constant, set in the constructor */
    UINT8 l, w;             /* Size of hitbox for collsion detection  */
    UINT8 lives;            /* How many lives this player has */
    int delta_x;            /* Signed integer, -1, 0, or 1 depending on movement */
    int bullet_type;        /* Will be 1 */
} Player;

typedef struct Alien {
    UINT32 x, y;            /* Position Coordinates */
    UINT8 l, w;             /* Size of hitbox for collision detection */
    int score;              /* Score awarded to Player */
    int alive;              /* To be used as a boolean marker 0 = true, -1 = false */ 
    /* Add bullet fire timing somewhere */
} Alien;

typedef struct Aliens{
    Alien array[5][9];     /* 5 rows of 9 aliens each */
    UINT8 totalAliens;
    int delta_x;           /* -8(left) or 8(right) depending on direction of movement */
    int bullet_type;       /* Will be -1 */
    char render;           /* For deciding if the whole aliens should be rendered */
} Aliens;

typedef struct Bullet {
    UINT16 x, y;        /* x coordinate should be set and not changed when the object is created */
    UINT8 l, w;         /* Hitbox */
    int delta_y;        /* displacement of bullet (should be 4) */
    int direc;          /* -1 or 1, moving down or up respectively */
    int is_active;      /* Tombstone for array check */
} Bullet;

typedef struct Score {
    UINT16 score;       /* Score number */
    UINT16 x, y;        /* Position of score sign */
} Score;

typedef struct Model {
    Player player;
    Aliens aliens;
    Score score;
    UINT16 lowbound_x, lowbound_y, highbound_x, highbound_y; /* Bounds of play area. highbounds should be bound - alien_w */ 
    UINT8 alien_l, alien_w; /* Used for movement and collision detection */      
    int alien_dx;
    int bullet_dy;
    Bullet active[30];  /* max active bullet entities */
    int active_count; 
    int quit;
    int lowest_alive; /* lowest alien alive, used for collision detection */
} Model;

/** 
 * @brief Moves the player based on the delta_x value
 * 
 * @param model Model struct
 * @param player Player struct
 */
void move_player(Player *player);

/** 
 * @brief Changes direction of movement (left or right), called when aliens are lowered
 * 
 * @param model Model struct
 * @param player Player struct
 */
void alien_direc_change(Aliens *alien_arr, int alien_dx);

/** 
 * @brief Moves the aliens based on the delta_x value
 * 
 * @param model Model struct
 * @param aliens Aliens struct
 */
int move_aliens(Aliens *aliens);

/** 
 * @brief Called when aliens x position meets edge, edge detection happens in update_aliens (events.c)
 * 
 * @param model Model struct
 * @param alien_arr Aliens struct
 */
int lower_aliens(Aliens *aliens, int highbound, int alien_dx);

/** 
 * @brief Called when bullet hitbox hits alien hitbox
 * 
 * @param alien Alien struct
 * @param curr_score Score struct
 */
void destroy_alien(Alien alien, Score curr_score);

/** 
 * @brief Moves the bullet based on the y_direction value
 * 
 * @param model Model struct
 * @param bullet Bullet struct
 */
int move_bullet(Model *model, Bullet *bullet);

/** 
 * @brief Adds alien score to the total score
 * 
 * @param score_to_add Score to add
 * @param curr_score Score struct
 */
void add_score (int score_to_add, Score curr_score);

/** 
 * @brief Updates the score
 * 
 * @param score Score struct
 */
void update_score(Score *score);

/**
 * @brief Checks if a bullet has hit an alien
 * 
 * @param aliens Aliens struct
 * @param bullet Bullet struct
 * @return 1 if bullet has hit, 0 otherwise
 */
int check_aliens_hit(Model *model, Bullet *bullet);

/**
 * @brief Checks if a bullet has hit a specific alien in a row
 * 
 * @param row Alien row
 * @param bullet Bullet struct
 * @return 1 if bullet has hit, 0 otherwise
 */
int check_row_hit(Alien row[], Bullet *bullet);

/**
 * @brief Checks if the player has been hit by a bullet
 * 
 * @param player Player struct
 * @param bullet Bullet struct
 * @return 1 if player has been hit, 0 otherwise
 */
int check_player_hit(Player *player, Bullet *bullet);

#endif