# 1 "model.c" 1
# 1 "./model.h" 1
# 1 "./types.h" 1
# 11 "./types.h"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 13 "./model.h" 2
# 1 "./effects.h" 1
# 1 "./psg.h" 1
# 1 "./TYPES.H" 1
# 12 "./psg.h" 2
# 19 "./psg.h"
 void write_psg(int reg, UINT8 val);
# 26 "./psg.h"
 void set_tone(int channel, int tuning);
# 33 "./psg.h"
 void set_volume(int channel, int volume);
# 41 "./psg.h"
 void enable_channel(int channel, int tone_on, int noise_on);




 void stop_sound();





 void set_noise(UINT8 tuning);
# 59 "./psg.h"
 void set_envelope(UINT8 shape, UINT16 sustain);
# 66 "./psg.h"
 UINT8 read_psg(int reg);
# 12 "./effects.h" 2





void play_shoot();




void play_hit();




void play_game_over();
# 14 "./model.h" 2


typedef struct Player {
    UINT16 x, y;
    UINT8 l, w;
    UINT8 lives;
    int delta_x;
    int bullet_type;
} Player;

typedef struct Alien {
    UINT32 x, y;
    UINT8 l, w;
    int score;
    int alive;

} Alien;

typedef struct Aliens{
    Alien array[5][9];
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
    int lowest_alive;
    int right_alive;
    int left_alive;
} Model;
# 75 "./model.h"
void move_player(Player *player);
# 83 "./model.h"
void alien_direc_change(Aliens *alien_arr, int alien_dx);
# 91 "./model.h"
int move_aliens(Aliens *aliens);
# 99 "./model.h"
int lower_aliens(Model *model, int highbound, int alien_dx);
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
# 149 "./model.h"
int check_row_hit(Model *model, Alien row[], Bullet *bullet);
# 158 "./model.h"
int check_player_hit(Player *player, Bullet *bullet);
# 165 "./model.h"
void update_lowest (Model *model);
# 172 "./model.h"
void update_left (Model *model);
# 179 "./model.h"
void update_right (Model *model);
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
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            aliens->array[i][j].x += aliens->delta_x;
        }
    }
    return 0;
}

int lower_aliens(Model *model, int highbound, int alien_dx) {


    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            model->aliens.array[i][j].y += 32;
        }
    }

    alien_direc_change(&model->aliens, alien_dx);

    if(((int)model->aliens.array[model->lowest_alive][0].y + 32) > (highbound - 48)) {
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

    if (bullet->y <= (model->lowbound_y + 32)) {
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
    int i;
    for (i = 0; i < 5; i++) {
        if (check_row_hit(model, model->aliens.array[i], bullet) == 1) {
            model->aliens.totalAliens -= 1;
            model->score.score += model->aliens.array[i][0].score;
            if (i == model->lowest_alive) {
                update_lowest(model);
            }
            return 1;
        }
    }
    return 0;
}

int check_row_hit(Model *model, Alien row[], Bullet *bullet) {
    int i;
    for(i = 0; i < 11; i += 1) {
        if (row[i].alive) {
            if((bullet->x >= row[i].x) && (bullet->x <= (row[i].x + 32)) && (bullet->y <= ((row[i].y) + 22))) {

                row[i].alive = 0;
                play_hit();

                if (i == model->left_alive) {
                    update_left(model);
                } else if (i == model->right_alive) {
                    update_right(model);
                }
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

void update_lowest (Model *model) {
    int i;

    while (model->lowest_alive >= 0) {
        for (i = 0; i < 9; i++) {
            if (model->aliens.array[model->lowest_alive][i].alive == 1) {
                return;
            }
        }
        model->lowest_alive -= 1;
    }
}

void update_left (Model *model) {
    int i;

    while (model->left_alive < 9) {
        for (i = 0; i < 5; i++) {
            if (model->aliens.array[i][model->left_alive].alive == 1) {
                return;
            }
        }
        model->left_alive += 1;
    }
}

void update_right (Model *model) {
    int i;

    while (model->right_alive >= 0) {
        for (i = 0; i < 5; i++) {
            if (model->aliens.array[i][model->right_alive].alive == 1) {
                return;
            }
        }
        model->right_alive -= 1;
    }
}
