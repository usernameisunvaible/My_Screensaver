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
#include "include/my_screensaver3.h"
#include "include/header.h"

void build_square_from_single_p (int *p, int len,
sfUint8 *framebuffer, sfColor color)
{
    for (int i = p[0] - (len / 2); i < p[0] + (len / 2); ++i) {
        for (int j = p[1] - (len / 2); j < p[1] + (len / 2); ++j)
            *(sfColor *)(4 * (i * WIDTH + j) + framebuffer) = color;
    }
}

csfml_t define_screen_s3 (csfml_t graph)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    graph.window = sfRenderWindow_create(mode, "screensaver_1",
    sfResize | sfClose | sfFullscreen , NULL);
    graph.texture = sfTexture_create(WIDTH, HEIGHT);
    graph.sprite = sfSprite_create();
    return graph;
}

void main_clock_s3 (sfUint8 *framebuffer, csfml_t graph)
{
    int *p = malloc(sizeof(int) * 2);
    sfColor color = sfRed;
    while (sfRenderWindow_isOpen(graph.window)) {
        event_clock(graph.window, graph.event);
        rgb(&color, RGB_SPEED);
        p[1] = rand() % ((WIDTH - (LEN))) + LEN / 2 ;
        p[0] = rand() % ((HEIGHT - (LEN))) + LEN / 2 ;
        build_square_from_single_p(p, LEN, framebuffer, color);
        upadate(graph.window, framebuffer, graph.sprite, graph.texture);
    }
    free(p);
}

int main_ss_3(void)
{
    srand(time(NULL));
    csfml_t graph = define_screen_s3(graph);
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));

    if (prepare_screen(graph.window, framebuffer, graph.sprite, graph.texture))
        return 1;
    main_clock_s3(framebuffer, graph);
    free(framebuffer);
    quit(graph.sprite, graph.texture, graph.window);
    return 0;
}