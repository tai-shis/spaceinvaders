#include "model.h"
#include <stdio.h>

int main()
{
    Model test = {
        { 0, 0, 32, 32, 3, 0, 1 },
        {
            { /* r1 */
                { 0, 0, 32, 32, 250, 0 },
                {32, 0, 32, 32, 250, 0},
                {64, 0, 32, 32, 250, 0},
                {96, 0, 32, 32, 250, 0},
                {128, 0, 32, 32, 250, 0},
                {160, 0, 32, 32, 250, 0},
                {192, 0, 32, 32, 250, 0},
                {224, 0, 32, 32, 250, 0},
                {256, 0, 32, 32, 250, 0},
                {288, 0, 32, 32, 250, 0},
                {320, 0, 32, 32, 250, 0}}, 
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
            1,
            -1
        },
        { 0, 0, 0 },
        0, 0, 0, 0,
        32, 32,
        32,
        1
    };

    printf("%d\n", test.aliens.r1[0].x);

    move_aliens(&test, &test.aliens);

    printf("%d\n", test.aliens.r1[0].x);

    return 0;
}