#include "model.h"
#include "events.h"
#include <osbind.h>
#include <stdio.h>

#define yield while(!Cconis()){} Cnecin();

int main() {
    Model test = {
        { 0, 0, 32, 32, 3, 0, 1 },
        {
            { /* r1 */
                { 0, 0, 32, 32, 250, 0},
                {32, 0, 32, 32, 250, 0},
                {64, 0, 32, 32, 250, 0},
                {96, 0, 32, 32, 250, 0},
                {128, 0, 32, 32, 250, 0},
                {160, 0, 32, 32, 250, 0},
                {192, 0, 32, 32, 250, 0},
                {224, 0, 32, 32, 250, 0},
                {256, 0, 32, 32, 250, 0},
                {288, 0, 32, 32, 250, 0},
                {320, 0, 32, 32, 250, 0}
            }, 
            { /* r2 */
                {0, 32, 32, 32, 200, 0},
                {32, 32, 32, 32, 200, 0},
                {64, 32, 32, 32, 200, 0},
                {96, 32, 32, 32, 200, 0},
                {128, 32, 32, 32, 200, 0},
                {160, 32, 32, 32, 200, 0},
                {192, 32, 32, 32, 200, 0},
                {224, 32, 32, 32, 200, 0},
                {256, 32, 32, 32, 200, 0},
                {288, 32, 32, 32, 200, 0},
                {320, 32, 32, 32, 200, 0}
            },
            { /* r3 */
                {0, 64, 32, 32, 150, 0},
                {32, 64, 32, 32, 150, 0},
                {64, 64, 32, 32, 150, 0},
                {96, 64, 32, 32, 150, 0},
                {128, 64, 32, 32, 150, 0},
                {160, 64, 32, 32, 150, 0},
                {192, 64, 32, 32, 150, 0},
                {224, 64, 32, 32, 150, 0},
                {256, 64, 32, 32, 150, 0},
                {288, 64, 32, 32, 150, 0},
                {320, 64, 32, 32, 150, 0}
            },
            { /* r4 */
                {0, 96, 32, 32, 100, 0},
                {32, 96, 32, 32, 100, 0},
                {64, 96, 32, 32, 100, 0},
                {96, 96, 32, 32, 100, 0},
                {128, 96, 32, 32, 100, 0},
                {160, 96, 32, 32, 100, 0},
                {192, 96, 32, 32, 100, 0},
                {224, 96, 32, 32, 100, 0},
                {256, 96, 32, 32, 100, 0},
                {288, 96, 32, 32, 100, 0},
                {320, 96, 32, 32, 100, 0}
            },
            { /* r5 */
                {0, 128, 32, 32, 50, 0},
                {32, 128, 32, 32, 50, 0},
                {64, 128, 32, 32, 50, 0},
                {96, 128, 32, 32, 50, 0},
                {128, 128, 32, 32, 50, 0},
                {160, 128, 32, 32, 50, 0},
                {192, 128, 32, 32, 50, 0},
                {224, 128, 32, 32, 50, 0},
                {256, 128, 32, 32, 50, 0},
                {288, 128, 32, 32, 50, 0},
                {320, 128, 32, 32, 50, 0}
            },
            55,
            8,
            -1
        },
        { 0, 0, 0 },
        0, 0, 630, 400,
        32, 32,
        8,
        1,
        {
            {0, 400, 8, 16, 4, 1, 1}, /* Player bullet */
            {0, 50, 8, 16, 4,-1, 1}, /* Alien bullet */
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        2
    };

    printf("Player Movement Testing: Press any key to begin\n");
    yield;
    printf("Moving Player to the right\n");
    async_move_player(&test, 'd'); /* Adjust this test once proper async is done */
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'd');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'd');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'd');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);

    printf("\nMoving Player to the left\n");
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);

    printf("\nPlayer left bound check, (x,y) should stay at lower bound.\n");
    test.player.x = test.lowbound_x;
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'a');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);

    printf("\nPlayer right bound check, (x,y) should stay at upper bound.\n");
    test.player.x = test.highbound_x;
    async_move_player(&test, 'd');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);
    async_move_player(&test, 'd');
    printf("(x,y): %d,%d\n", test.player.x, test.player.y);


    printf("\nPlayer movement testing complete: Press any key to go to next test\n");
    printf("------------------------------------------------------------------\n");
    yield;

    printf("Alien Movement Testing: Press any key to begin\n");
    yield;

    printf("Moving aliens to the right\n");
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);

    printf("\nMoving aliens back to left edge\n");
    test.aliens.delta_x = -8;
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);

    printf("\nNext move to left should trigger boundary, and lower aliens\n");
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);

    printf("\nAlien direction should now change back to right\n");
    update_aliens(&test);
    printf("(x,y): %d,%d\n", test.aliens.r1[0].x, test.aliens.r1[0].y);

    printf("\nAlien movement testing complete: Press any key to go to next test\n");
    printf("-----------------------------------------------------------------\n");
    yield;

    printf("Bullet Movement Testing: Press any key to begin\n");
    yield;

    printf("Player shooting bullet up\n");
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    move_bullet(&test, &test.active[0]);
    printf("(x,y): %d,%d\n", test.active[0].x, test.active[0].y);
    
    printf("\nPress any key to test alien bullet\n");
    yield;

    printf("Alien shooting bullet down\n");
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);
    move_bullet(&test, &test.active[1]);
    printf("(x,y): %d,%d\n", test.active[1].x, test.active[1].y);

    printf("\nBullet movement testing complete, all tests complete\n");

    return 0;
}