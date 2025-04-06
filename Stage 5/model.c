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

int lower_aliens(Model *model, int highbound, int alien_dx) {
    /* Called when aliens x position meets edge, edge detection happens in move_aliens */
    /* Also changes direction of travel */
    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            model->aliens.array[i][j].y += 32; /* Move down */
        }
    }
    
    alien_direc_change(&model->aliens, alien_dx);

    if(((int)model->aliens.array[model->aliens.lowest_alive][0].y + 32) > (highbound - 48)) {
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
    if (bullet->direc == 1) {
        bullet->y -= bullet->delta_y;
        if (bullet->y <= (model->lowbound_y + 32)) {
            return 1;
        }
    } else {
        bullet->y += bullet->delta_y;
        if ((bullet->y + 14) >= (model->highbound_y - 32)) {
            return 1;
        }
    }
    return 0;
}

void add_score (int score_to_add, Score curr_score) {
    /* Adds score from destorying alien */
    curr_score.score += score_to_add;
}

int check_aliens_hit(Model *model, Bullet *bullet) {
    int i;
    for (i = 0; i < 5; i++) {
        if (check_row_hit(model, model->aliens.array[i], bullet) == 1) {
            model->aliens.totalAliens -= 1;
            model->score.score += model->aliens.array[i][0].score;
            if (i == model->aliens.lowest_alive) {
                update_lowest(model);
            }
            lowest_alive(&model->aliens);
            return 1;
        }
    }
    return 0;
}

int check_row_hit(Model *model, Alien row[], Bullet *bullet) {
    int i;
    for(i = 0; i < 11; i += 1) {
        if (row[i].alive) {
            if((bullet->x >= row[i].x) && (bullet->x <= (row[i].x + 32)) && (bullet->y <= ((row[i].y) + 22)) && (bullet->y >= row[i].y)) {
                /* bullet hits alien */
                row[i].alive = 0;

                if (i == model->aliens.left_alive) {
                    update_left(model);
                } else if (i == model->aliens.right_alive) {
                    update_right(model);
                }
                return 1;
            }
        }
    }
}

int check_player_hit(Player *player, Bullet *bullet) {
    if (((bullet->x + 4) >= player->x) && (bullet->x <= (player->x + 32)) && (bullet->y >= player->y)) {
        player->lives -= 1;
        return 1;
    }
    return 0;
}

void update_lowest (Model *model) {
    int i;

    while (model->aliens.lowest_alive >= 0) {
        for (i = 0; i < 9; i++) {
            if (model->aliens.array[model->aliens.lowest_alive][i].alive == 1) {
                return; /* Found an alien in the row */
            }
        }
        model->aliens.lowest_alive -= 1; /* No aliens in this row, check next row */
    }
}

void update_left (Model *model) {
    int i;

    while (model->aliens.left_alive < 9) {
        for (i = 0; i < 5; i++) {
            if (model->aliens.array[i][model->aliens.left_alive].alive == 1) {
                return; /* Found an alien in the column */
            }
        }
        model->aliens.left_alive += 1; /* No aliens in this column, check next column */
    }
}

void update_right (Model *model) {
    int i;

    while (model->aliens.right_alive >= 0) {
        for (i = 0; i < 5; i++) {
            if (model->aliens.array[i][model->aliens.right_alive].alive == 1) {
                return; /* Found an alien in the column */
            }
        }
        model->aliens.right_alive -= 1; /* No aliens in this column, check next column */
    }
}

void lowest_alive (Aliens *aliens) {
    int i;
    int j;
    for (i = 0; i < 9; i++) {
        aliens->lowest_alien[i] = -1; /* Default to -1, means no aliens in column */
        for (j = 4; j >= 0; j--) {
            if (aliens->array[j][i].alive == 1) {
                aliens->lowest_alien[i] = j;
                break;
            }
        }
    }
}