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

void draw_rect(int *p1, int *p2, sfUint8 *framebuffer, sfColor color)
{
    for (int i = p1[0]; i < p2[0]; i++){
        for (int j = p1[1]; j < p2[1]; j++) {
            *(sfColor *)(4 * (i * WIDTH + j) + framebuffer) = color;
        }
    }
}

sfColor line_drawing(int nbr, int min)
{
    if (nbr < min) {
        return sfRed;
    }
    return sfWhite;
}

int biggest_number(int **lab)
{
    int biggest = 1;
    for (int i = 0; i < LEN_LAB_X; ++i) {
        for (int j = 0; j < LEN_LAB_Y; ++j) {
            if (lab[i][j] > biggest)
                biggest = lab[i][j];
        }
    }
    return biggest + 1;
}

void draw_line_lab(int **lab)
{
    int x_y[2] = {LEN_LAB_X - 1, LEN_LAB_Y - 2};

    recursion_line(lab, x_y, lab[LEN_LAB_X - 1][LEN_LAB_Y - 2], -1024);
}

float refresh_lab_resolve(float max, int beeg, int **lab)
{
    if (max >= beeg && max != beeg + VITESSE_DRAW * 2) {
        lab[0][1] = 2;
        draw_line_lab(lab);
        return beeg + VITESSE_DRAW * 2;
    }
}