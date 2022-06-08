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

void draw_entry_rect(sfUint8 *framebuffer)
{
    int *p1 = malloc(sizeof(int) * 2);
    int *p2 = malloc(sizeof(int) * 2);

    p1[0] = 0 * TAILLE_BLOCS;
    p1[1] = 1 * TAILLE_BLOCS;
    p2[0] = 0 * TAILLE_BLOCS + TAILLE_BLOCS;
    p2[1] = 1 * TAILLE_BLOCS+ TAILLE_BLOCS;
    draw_rect(p1, p2, framebuffer, my_select_rgba(0, 255, 0, 255));
    free(p1);
    free(p2);
}

void draw_lab_p2 (sfUint8 *framebuffer, int **lab, int max, int i)
{
    int *p1 = malloc(sizeof(int) * 2);
    int *p2 = malloc(sizeof(int) * 2);

    for (int j = 0; j < LEN_LAB_Y; ++j) {
        p1[0] = i * TAILLE_BLOCS;
        p1[1] = j * TAILLE_BLOCS;
        p2[0] = i * TAILLE_BLOCS + TAILLE_BLOCS;
        p2[1] = j * TAILLE_BLOCS+ TAILLE_BLOCS;
        if (lab[i][j] == 0)
            draw_rect(p1, p2, framebuffer, my_select_rgba(0, 0, 0, 255));
        else if (lab[i][j] < 0)
            draw_rect(p1, p2, framebuffer, line_drawing(lab[i][j], max));
        else
            draw_rect(p1, p2, framebuffer, color_lab(lab[i][j], max));
        }
    free(p1);
    free(p2);
}

void draw_lab(sfUint8 *framebuffer, int **lab, int max)
{
    for (int i = 0; i < LEN_LAB_X; ++i) {
        draw_lab_p2(framebuffer, lab, max, i);
    }
    draw_entry_rect(framebuffer);
}
