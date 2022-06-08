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

void color_lab_p2(int nbr, int max, int *rgb)
{
    if (nbr >= 767 && nbr < 1023) {
        rgb[2] = 767 - (nbr - 767);
        rgb[1] = 0;
        rgb[0] = 255;
    }
    if (nbr > max) {
        rgb[0] = 255;
        rgb[1] = 255;
        rgb[2] = 255;
    }
}

sfColor color_lab(int nbr, int max)
{
    int rgb[3] = {0, 255, 0};

    if (nbr > 0 && nbr < 255)
        rgb[2] = nbr;
    if (nbr >= 255 && nbr < 511) {
        rgb[2] = 255;
        rgb[1] = 255 - (nbr - 255);
        rgb[0] = 0;
    }
    if (nbr >= 511 && nbr < 767 ) {
        rgb[2] = 255;
        rgb[1] = 0;
        rgb[0] = nbr - 511;
    }
    color_lab_p2(nbr, max, rgb);
    return my_select_rgba(rgb[0], rgb[1], rgb[2], 255);
}