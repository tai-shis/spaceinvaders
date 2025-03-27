#include "model.h"

void move_player(Player *player) {
    /* Should be called every tick/check whenever the player's directional value is not 0 */
    player->x += player->delta_x;
}

void alien_direc_change(Aliens *alien_arr, int alien_dx) {
    /* Changes direction of movement (left or right), called when aliens are lowered */
    if (alien_arr->delta_x > 0) {
        alien_arr->delta_x = -8;
    }
    else {
        alien_arr->delta_x = 8;
    }
    return;
}

int move_aliens(Aliens *aliens) {
    /* Should be called every time that aliens are set to move left/right */
    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            aliens->array[i][j].x += aliens->delta_x;
        }
    }
    return 0;
}

int lower_aliens(Aliens *aliens, int highbound, int alien_dx) {
    /* Called when aliens x position meets edge, edge detection happens in move_aliens */
    /* Also changes direction of travel */
    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            aliens->array[i][j].y += 32; /* Move down */
        }
    }
    
    alien_direc_change(aliens, alien_dx);

    if(((int)aliens->array[4][0].y + 32) > (highbound - 48)) {
        return -1; /* Game over */
    } else {
        return 0;
    }
}

void destroy_alien(Alien alien, Score curr_score) {
    /* Called when bullet hitbox hits alien hitbox */
    /* Total alien count changed from collision handling point */
    /* Also adds score from destroying alien */
    add_score(alien.score, curr_score);
    alien.alive = -1;
}

int move_bullet(Model *model, Bullet *bullet) {
    /* Should be called every tick to handle the bullet's movement */
    /* If returns -1, event handlers should remove this object instance */
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
    /* Adds score from destorying alien */
    curr_score.score += score_to_add;
}

void update_score(Score *score) {
    /* redisplay score */
}

int check_aliens_hit(Model *model, Bullet *bullet) {
    if(check_row_hit(model->aliens.array[0], bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.array[0][0].score;
        return 1;
    } 
    if(check_row_hit(model->aliens.array[1], bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.array[1][0].score;
        return 1;
    } 
    if(check_row_hit(model->aliens.array[2], bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.array[2][0].score;
        return 1;
    } 
    if(check_row_hit(model->aliens.array[3], bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.array[3][0].score;
        return 1;
    } 
    if(check_row_hit(model->aliens.array[4], bullet) == 1) {
        model->aliens.totalAliens -= 1;
        model->score.score += model->aliens.array[4][0].score;
        return 1;
    }
    return 0;
}

int check_row_hit(Alien row[], Bullet *bullet) {
    int i;
    for(i = 0; i < 11; i += 1) {
        if (row[i].alive) {
            if((bullet->x >= row[i].x) && (bullet->x <= (row[i].x + 32)) && (bullet->y <= ((row[i].y) + 22))) {
                /* bullet hits alien */
                row[i].alive = 0;
                play_hit();
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
