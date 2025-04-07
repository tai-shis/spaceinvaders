#include "render.h"

extern void clear_screen(UINT32 base);

void render(Model *model, void *base, int f) {
    int i;

    /* Always render player for simplicity */
    render_player(&model->player, base);

    render_lives(model->player.lives, base);

    render_border(model, base);

    /* If aliens need to be rendered, also render score probably */ 
    if (model->aliens.render == 1) {
        render_aliens(&model->aliens, base, (f&1));
        render_score(&model->score, base);
        model->aliens.render == 1;
    }

    /* Check if there are any bullets that need to be rendered */
    if (model->active_count > 0) {
        for (i = 0; i < 30; i += 1) {
            if (model->active[i].is_active == 1) {   
                render_bullet(&model->active[i], base);
            }
        }
    }
}

void render_player(const Player *player, UINT32 *base) {
    plot_bitmap32(base, player->x, player->y, player_bitmap, 32);
}

void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap) {
    plot_bitmap32(base, alien->x, alien->y, bitmap, 32);
}

void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f) {
    /* Assuming f is 0/1 based on odd/even frame */
    int i;
    int j;
    int k;
    UINT32 old_frame = f;
    UINT32 opp_frame;
    if (f == 0){
        opp_frame = 1;
    } else {
        opp_frame = 0;
    }

    for (i = 0; i < 5; i++) {
        /* if else chain below checks to see which row for getting correct bitmap */
        if (i == 0) {
            k = 2;
        } else if (i <= 2) {
            k = 1;
            if (i == 2) {
                f = opp_frame;
            }
        } else {
            f = old_frame;
            k = 0;
            if (i == 4) {
                f = opp_frame;
            }
        }

        for (j = 0; j < 9; j++) {
            if (aliens->array[i][j].alive) {
                render_alien(&aliens->array[i][j], base, alien_maps[k][f]);
            }
        }
    }
}

void render_bullet(const Bullet *bullet, UINT8 *base) {
    /* Change height based on length of bullet */
    if (bullet->direc == 1) {
        plot_bitmap8(base, bullet->x, bullet->y, bullet_bitmaps[0], 16);
    } else {
        plot_bitmap8(base, bullet->x, bullet->y, bullet_bitmaps[1], 16);
    }
}

void render_score(const Score *score, UINT16 *base) {
    /* Inefficient score render, assuming score is max a 6 digit integer */
    /* Is there a way to do this with bitshifts? */
    int out, i;
    int temp;
    temp = score->score;

    for(i = 80; i >= 0; i -= 16) { /* Go backwards, 16 for size of spacing used in coordinate calculation */
        out = temp % 10;
        temp /= 10;

        /* Could also use plot ch, not too much of a difference */
        plot_bitmap16(base, score->x + i, score->y, nums[out], 16);
    }
};

void render_lives(UINT8 lives, UINT16 *base) {
    switch(lives) {
        case 3:
            plot_bitmap16(base, 16, 8, heart, 16);
            plot_bitmap16(base, 36, 8, heart, 16);
            plot_bitmap16(base, 56, 8, heart, 16);
            break;
        case 2:
            plot_bitmap16(base, 16, 8, heart, 16);
            plot_bitmap16(base, 36, 8, heart, 16);
            plot_bitmap16(base, 56, 8, broken_heart, 16);
            break;
        case 1:
            plot_bitmap16(base, 16, 8, heart, 16);
            plot_bitmap16(base, 36, 8, broken_heart, 16);
            plot_bitmap16(base, 56, 8, broken_heart, 16);
            break;
    }
};

void render_border(Model *model, void *base){
    plot_hline(base, model->lowbound_x, model->highbound_x, (model->player.y) + 33);
    plot_hline(base, model->lowbound_x, model->highbound_x, 32);
}

void render_title(UINT32 *base) {
    plot_custom(base, 125, 125, title_bitmap, 24, 12);
    plot_custom(base, 215, 200, start_bitmap, 40, 6);
    plot_custom(base, 270, 250, quit_bitmap, 40, 3);
}