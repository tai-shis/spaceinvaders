# 1 "model.c" 1
# 1 "./model.h" 1
# 1 "./types.h" 1
# 11 "./types.h"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 13 "./model.h" 2


typedef struct Player {
    UINT16 x, y;
    UINT8 l, w;
    UINT8 lives;
    int delta_x;
    int bullet_type;
} Player;

typedef struct Alien {
    UINT16 x, y;
    UINT8 l, w;
    int score;
    int alive;

} Alien;

typedef struct Aliens{
    Alien r1[9];
    Alien r2[9];
    Alien r3[9];
    Alien r4[9];
    Alien r5[9];
    UINT8 totalAliens;
    int delta_x;
    int bullet_type;
    char render;
} Aliens;

typedef struct Bullet {
    UINT16 x, y;
    UINT8 l, w;
    int delta_y;
    int direc;
    int is_active;
} Bullet;

typedef struct Score {
    UINT16 score;
    UINT16 x, y;
} Score;

typedef struct Model {
    Player player;
    Aliens aliens;
    Score score;
    UINT16 lowbound_x, lowbound_y, highbound_x, highbound_y;
    UINT8 alien_l, alien_w;
    int alien_dx;
    int bullet_dy;
    Bullet active[30];
    int active_count;
    int quit;
} Model;
# 75 "./model.h"
void move_player(Player *player);
# 83 "./model.h"
void alien_direc_change(Aliens *alien_arr, int alien_dx);
# 91 "./model.h"
int move_aliens(Aliens *aliens);
# 99 "./model.h"
int lower_aliens(Aliens *alien_arr, int highbound, int alien_dx);
# 107 "./model.h"
void destroy_alien(Alien alien, Score curr_score);
# 115 "./model.h"
int move_bullet(Model *model, Bullet *bullet);
# 123 "./model.h"
void add_score (int score_to_add, Score curr_score);
# 130 "./model.h"
void update_score(Score *score);
# 139 "./model.h"
int check_aliens_hit(Model *model, Bullet *bullet);
# 148 "./model.h"
int check_row_hit(Alien row[], Bullet *bullet);
# 157 "./model.h"
int check_player_hit(Player *player, Bullet *bullet);
# 1 "model.c" 2


void move_player(Player *player) {

    player->x += player->delta_x;
}

void alien_direc_change(Aliens *alien_arr, int alien_dx) {

    if (alien_arr->delta_x > 0) {
        alien_arr->delta_x = -8;
    }
    else {
        alien_arr->delta_x = 8;
    }
    return;
}

int move_aliens(Aliens *aliens) {

    int i;
    for (i = 0; i < 9; i++) {
        aliens->r1[i].x += aliens->delta_x;
        aliens->r2[i].x += aliens->delta_x;
        aliens->r3[i].x += aliens->delta_x;
        aliens->r4[i].x += aliens->delta_x;
        aliens->r5[i].x += aliens->delta_x;
    }
    return 0;
}

int lower_aliens(Aliens *alien_arr, int highbound, int alien_dx) {


    int i;
    for (i = 0; i < 9; i++) {
        alien_arr->r1[i].y += 32;
        alien_arr->r2[i].y += 32;
        alien_arr->r3[i].y += 32;
        alien_arr->r4[i].y += 32;
        alien_arr->r5[i].y += 32;
    }

    alien_direc_change(alien_arr, alien_dx);

    if((int)alien_arr->r5[0].y + 32 > highbound - 48) {
        return -1;
    } else {
        return 0;
    }
}

void destroy_alien(Alien alien, Score curr_score) {



    add_score(alien.score, curr_score);
    alien.alive = -1;
}

int move_bullet(Model *model, Bullet *bullet) {


    if (bullet->direc == -1) {
        bullet->y += bullet->delta_y;
    } else {
        bullet->y -= bullet->delta_y;
    }

    if (bullet->y <= model->lowbound_y) {
        return -1;
    } else if ((bullet->y + 16) >= model->highbound_y) {
        return -1;
    } else {
        return 0;
    }
}

void add_score (int score_to_add, Score curr_score) {

    curr_score.score += score_to_add;
}

void update_score(Score *score) {

}

int check_aliens_hit(Model *model, Bullet *bullet) {
    if(check_row_hit(model->aliens.r1, bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.r1[0].score;
        return 1;
    }
    if(check_row_hit(model->aliens.r2, bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.r2[0].score;
        return 1;
    }
    if(check_row_hit(model->aliens.r3, bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.r3[0].score;
        return 1;
    }
    if(check_row_hit(model->aliens.r4, bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.r4[0].score;
        return 1;
    }
    if(check_row_hit(model->aliens.r5, bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.r5[0].score;
        return 1;
    }
    return 0;
}

int check_row_hit(Alien row[], Bullet *bullet) {
    int i;
    for(i = 0; i < 11; i += 1) {
        if (row[i].alive) {
            if((bullet->x >= row[i].x) && (bullet->x <= (row[i].x + 32)) && (bullet->y <= ((row[i].y) + 22))) {

                row[i].alive = 0;
                return 1;
            }
        }
    }
}

int check_player_hit(Player *player, Bullet *bullet) {
    if ((bullet->x >= player->x) && (bullet->x <= (player->x + 32)) && ((bullet->y + 8) >= player->y)) {
        player->lives -= 1;
        return 1;
    }
}
