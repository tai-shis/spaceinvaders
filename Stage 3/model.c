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
    for (i = 0; i < 11; i++) {
        aliens->r1[i].x += aliens->delta_x;
        aliens->r2[i].x += aliens->delta_x;
        aliens->r3[i].x += aliens->delta_x;
        aliens->r4[i].x += aliens->delta_x;
        aliens->r5[i].x += aliens->delta_x;
    }
    return 0;
}

int lower_aliens(Aliens *alien_arr, int highbound, int alien_dx) {
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
    
    alien_direc_change(alien_arr, alien_dx);

    if((int)alien_arr->r5[0].y >= highbound-32) {
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
    bullet->y -= bullet->delta_y;

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

int check_aliens_hit(Aliens *aliens, Bullet *bullet) {
    if(check_row_hit(aliens->r1, bullet) == 1) {
        aliens.totalAliens -= 1;
        return 1;
    } 
    if(check_row_hit(aliens->r2, bullet) == 1) {
        aliens.totalAliens -= 1;
        return 1;
    } 
    if(check_row_hit(aliens->r3, bullet) == 1) {
        aliens.totalAliens -= 1;
        return 1;
    } 
    if(check_row_hit(aliens->r4, bullet) == 1) {
        aliens.totalAliens -= 1;
        return 1;
    } 
    if(check_row_hit(aliens->r5, bullet) == 1) {
        aliens.totalAliens -= 1;
        return 1;
    } 
}

int check_row_hit(Alien *row[], Bullet *bullet) {
    int i;
    for(i = 0; i < 11; i += 1) {
        if((bullet->x > row[i]->x) && (bullet->x < row[i]->x + 32)) {
            /* bullet hits alien */
            row[i]->alive = 0;
            return 1;
        }
    }
}

int check_player_hit(Player *player, Bullet *bullet) {
    if ((bullet->x > player->x) && (bullet->x < player->x + 32)) {
        player->lives -= 1;
        return 1;
    }
} 
