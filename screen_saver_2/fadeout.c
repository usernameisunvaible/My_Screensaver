/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "include/my_screensaver2.h"
#include "include/header.h"

void modif_aplha (sfUint8 *framebuffer, int value, int i)
{
    for (int j = 0; j < HEIGHT; ++j)
        (*(sfColor *)(4 * (j * WIDTH + i) + framebuffer)).a += value;
}

int fadeout_apply(int fadeout, int **lab, sfUint8 *framebuffer)
{
    if (fadeout > 128 && fadeout < 257) {
        for (int i = 0; i < WIDTH; ++i) {
            modif_aplha(framebuffer, -2, i);
        }
        --fadeout;
    }
    if (fadeout == 128)
        draw_lab(framebuffer, lab, 0);
    if (fadeout > 0 && fadeout < 129) {
        for (int i = 0; i < WIDTH; ++i)
            modif_aplha(framebuffer, 2, i);
        --fadeout;
    }
    return fadeout;
}
