#include "events.h"
#include <stdio.h>

void async_move_player(Model *model, char key) {
    if(key == 'a') {
        model->player.delta_x = -8; /* How many px to move */
    } else if(key == 'd') {
        model->player.delta_x = 8;
    } else {
        model->player.delta_x = 0;
    }

    move_player(&model->player);

    if((int)model->player.x <= (int)model->lowbound_x) {
        model->player.x = model->lowbound_x;
    } else if ((model->player.x + 22) > model->highbound_x) {
        model->player.x = model->highbound_x - 22;
    } else {
        return;
    }
}    

void async_shoot(Model *model, int cooldown) {
    /* cooldown will probably just be the clock counter or something, */
    /* will just be used as an arbitrary check if the player can shoot or not */
    
    /* For now, make a new bullet object when this is called, is ineffecient though */
    /* 1 for moving up, edit bulletX once mapping is done */
    int i;
    Bullet temp = {0, 0, 8, 16, 8, 1, 1};
    temp.x = model->player.x + 14;  /* Center of player */
    temp.y = model->player.y - 6;  /* Top of player - bullet height (and some change)*/
    
    if((cooldown != 0) || (model->active_count == 30)) {
        /* Either at max entities or cooldown not reached yet */
        return;
    } else {
        /* Find next empty location in array */
        for(i = 0; i < 30; i+=1) {
            if(!model->active[i].is_active) {
                model->active[i] = temp;
                model->active_count += 1;
                return;
            }
        }
    }
}

int update_aliens(Model *model) {
    if (model->aliens.delta_x == -8) {
        if ((int)(model->aliens.r1[0].x + model->aliens.delta_x) < (int)model->lowbound_x) {
            return lower_aliens(&model->aliens, model->highbound_y, model->alien_dx);
        }
    } else if (model->aliens.delta_x == 8) {
        if ((int)(model->aliens.r1[8].x + model->aliens.delta_x + 16) > (int)model->highbound_x) {
            return lower_aliens(&model->aliens, model->highbound_y, model->alien_dx);
        }
    } 

    move_aliens(&model->aliens);
    model->aliens.render = 1;
    return 0;
}

void update_bullets(Model *model) {
    /* For now, will detect if bullet goes out of bounds */
    int i, deactivate, hit = 0;
    for(i = 0; i < 30; i += 1) {
        /* Find only active bullets */
        if(model->active[i].is_active) {
            /* Update position, use return to deactivate or not */
            deactivate = move_bullet(model, &model->active[i]);
            
            if(model->active[i].direc == 1) { 
                /* Check for alien collision */
                hit = check_aliens_hit(model, &model->active[i]);
                if(hit == 1) {
                    /* Done specifically this way so we dont override if render is already on */
                    model->aliens.render = 1; /* If collision is detected, make sure to render next render cycle */
                }
            } else {
                /* Otherwise check for player collision */
                hit = check_player_hit(&model->player, &model->active[i]);
            }
    
            if((deactivate == -1) || hit) {
                model->active[i].is_active = 0;
                model->active_count -= 1;
            }
        }
    }
}

int check_endgame(Model *model) {
    /* TODO: move game over from lower aliens to here */
    if (model->player.lives == 0) {
        return 1;
    }
    if (model->aliens.totalAliens == 0) {
        return 1;
    }
    /* possibly missing other game over conditions */
    return 0;
}