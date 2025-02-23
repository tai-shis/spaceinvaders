#include "model.h"

void move_player(Model *model, Player *player) {
    /* Should be called every tick/check whenever the player's directional value is not 0 */
    player->x += player->delta_x;

    if(player->x <= model->lowbound_x) {
        player->x = model->lowbound_x;
    } else if (player->x >= model->highbound_x) {
        player->x = model->highbound_x;
    } else {
        return;
    }
}

void alien_direc_change(Model *model, Aliens *alien_arr) {
    /* Changes direction of movement (left or right), called when aliens are lowered */
    if (alien_arr->delta_x > 0) {
        alien_arr->delta_x = -model->alien_dx;
    }
    else {
        alien_arr->delta_x = model->alien_dx;
    }
    return;
}

int move_aliens(Model *model, Aliens *aliens) {
    /* Should be called every time that aliens are set to move, handles lowering aliens when necessary */
    /* Assumes that the losing condition is reliant on the lowest possible position that an alien can be at*/
    /* Returns -1 is aliens hits lower bound*/

    /* Uses return value of lower_aliens() to check if game ends */
    /* Also checks if next step will be out of bounds, and if so it lowers aliens instead */
    if (((aliens->r1[0].x + aliens->delta_x) <= model->lowbound_x) && (aliens->delta_x == -1)) {
        return lower_aliens(model, aliens);
    } else if (((aliens->r1[0].x + aliens->delta_x) >= model->highbound_x) && (aliens->delta_x == 1)) {
        return lower_aliens(model, aliens);
    } else {
        int i;
        for (i = 0; i < 11; i++) {
            aliens->r1[i].x += aliens->delta_x;
            aliens->r2[i].x += aliens->delta_x;
            aliens->r3[i].x += aliens->delta_x;
            aliens->r4[i].x += aliens->delta_x;
            aliens->r5[i].x += aliens->delta_x;
        }
        return 0;
    }
}

int lower_aliens(Model *model, Aliens *alien_arr) {
    /* Called when aliens x position meets edge, edge detection happens in move_aliens */
    /* Also changes direction of travel */
    int i;
    for (i = 0; i < 11; i++) {
        alien_arr->r1[i].y -= 32;
        alien_arr->r2[i].y -= 32;
        alien_arr->r3[i].y -= 32;
        alien_arr->r4[i].y -= 32;
        alien_arr->r5[i].y -= 32;
    }
    alien_direc_change(model, alien_arr);    

    if(alien_arr->r5[0].y >= model->lowbound_y) {
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
    bullet->y += bullet->y_direction;

    if (bullet->y <= model->lowbound_y) {
        return -1;
    } else if (bullet->y >= model->highbound_y) {
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