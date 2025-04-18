#include "render.h"
#include "raster.h"
#include "bitmaps.c"

void render(const Model *model, void *base, int f) {
    render_player(&model->player, base);
    render_aliens(&model->aliens, base, f);
    /* Not used for now */
    render_bullet(&model->active[0], base);
    render_bullet(&model->active[1], base);
    render_score(&model->score, base);
}

void render_player(const Player *player, UINT32 *base) {
    plot_bitmap32(base, player->x, player->y, player_bitmap, 32);
}

void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap) {
    plot_bitmap32(base, alien->x, alien->y, bitmap, 32);
}

void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f) {
    /* Assuming f is 0/1 based on odd/even frame */
    
    /* Render r1-r5 */
    int i;
    for(i = 0; i < 11; i++) {
        render_alien(&aliens->r1[i], base, alien3_bitmap[f]);
    }

    for(i = 0; i < 11; i++) {
        render_alien(&aliens->r2[i], base, alien1_bitmap[f]);
    }

    for(i = 0; i < 11; i++) {
        render_alien(&aliens->r3[i], base, alien1_bitmap[f]);
    }

    for(i = 0; i < 11; i++) {
        render_alien(&aliens->r4[i], base, alien2_bitmap[f]);
    }

    for(i = 0; i < 11; i++) {
        render_alien(&aliens->r5[i], base, alien2_bitmap[f]);
    }
}

void render_bullet(const Bullet *bullet, UINT8 *base) {
    /* Change height based on length of bullet */
    plot_bitmap8(base, bullet->x, bullet->y, bullet_bitmap, 16);
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
