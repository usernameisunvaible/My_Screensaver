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
#include "include/my_screensaver4.h"
#include "include/header.h"

void create_balls(ball_t *balls)
{
    for (int i = 0; i < NBR_BALLS; ++i) {
        balls[i].x1 = ((WIDTH/(NBR_BALLS + 1)) * (i + 1)) - TAILLE_BALL / 2 ;
        balls[i].y1 = (HEIGHT - (TAILLE_BALL));
        balls[i].x2 = ((WIDTH/(NBR_BALLS + 1)) * (i + 1)) + TAILLE_BALL / 2;
        balls[i].y2 = (HEIGHT - (TAILLE_BALL)) + TAILLE_BALL;
        balls[i].counter = JUMP_HIGH * -1;
        balls[i].start = 0;
        balls[i].color = sfRed;
    }
}

csfml_t define_screen_s4 (csfml_t graph)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    graph.window = sfRenderWindow_create(mode, "screensaver_1",
    sfResize | sfClose | sfFullscreen , NULL);
    graph.texture = sfTexture_create(WIDTH, HEIGHT);
    graph.sprite = sfSprite_create();
    return graph;
}