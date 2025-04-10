#ifndef MODEL_H
#define MODEL_H

#include "types.h"

typedef struct Player {
    UINT16 x, y;            /* Position Coordinates, y should be constant, set in the constructor */
    UINT8 l, w;             /* Size of hitbox for collsion detection  */
    UINT8 lives;            /* How many lives this player has */
    int delta_x;            /* Signed integer, -1, 0, or 1 depending on movement */
    int bullet_type;        /* Will be 1 */
} Player;

typedef struct Alien {
    UINT16 x, y;               /* Position Coordinates */
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
    int delta_x;           /* -8(left) or 8(right) depending on direction of movement */
    int bullet_type;       /* Will be -1 */
} Aliens;

typedef struct Bullet {
    UINT16 x, y;        /* x coordinate should be set and not changed when the object is created */
    UINT8 l, w;         /* Hitbox */
    int delta_y;        /* -1 or 1, moving down or up respectively */
    char is_active;     /* Tombstone for array check */
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
} Model;

/** 
 * @brief Moves the player based on the delta_x value
 * 
 * @param player Player struct
 */
void move_player(Player *player);

/** 
 * @brief Changes direction of movement (left or right), called when aliens are lowered
 * 
 * @param alien_arr All aliens
 * @param alien_dx Horizontal velocity of the alien
 */
void alien_direc_change(Aliens *alien_arr, int alien_dx);

/** 
 * @brief Moves the aliens based on the delta_x value
 * 
 * @param aliens Aliens struct
 */
int move_aliens(Aliens *aliens);

/** 
 * @brief Called when aliens x position meets edge, edge detection happens in move_aliens
 * 
 * @param alien_arr Aliens struct
 * @param highbout Upper screen boundary
 * @param alien_dx Horizontal velocity of the alien
 */
int lower_aliens(Aliens *alien_arr, int highbound, int alien_dx);

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
 * @brief Checks if the bullet given collides with any Aliens
 * 
 * @param aliens All Aliens struct
 * @param bullet Bullet instance
 */
int check_aliens_hit(Aliens *aliens, Bullet *bullet);

/** 
 * @brief Checks if the bullet given collides the given row of Aliens
 * 
 * @param row Row to check for collision
 * @param bullet Bullet instance
 */
int check_row_hit(Alien *row[], Bullet *bullet);

/** 
 * @brief Checks if the bullet given collides the player
 * 
 * @param player Player struct
 * @param bullet Bullet instance
 */
int check_player_hit(Player *player, Bullet *bullet);

/** 
 * @brief Checks if the game should end
 * 
 * @param model Gamestate
 */
int check_endgame(Model *model);

#endif