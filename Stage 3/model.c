#include "model.h"

void move_player(Model *model, Player *player) {
    if(player->x <= model->lowbound_x) {
        player->x = model->lowbound_x;
    } else if (player->x >= model->highbound_x) {
        player->x = model->highbound_x;
    } else {
        player->x += player->direction;
    }
}



void alien_direc_change(Aliens *alien_arr) {
    if (alien_arr->direction > 0) {
        alien_arr->direction = -1;
    }
    else {
        alien_arr->direction = 1;
    }

    return;
}

int move_bullet(Model *model, Bullet *bullet) {
    /* If returns -1, event handlers should remove this object instance */
    if (bullet->y <= model->lowbound_y) {
        return -1;
    } else if (bullet->y >= model->highbound_y) {
        return -1;
    } else {
        bullet->y += bullet->y_direction;
        return 0;
    }
}