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
#include "include/my_screensaver5.h"
#include "include/header.h"
#include <math.h>

#define BALL_R 156


void circle_draw_points(int *p_buf, sfUint8 *framebuffer,
int *p, sfColor color)
{
    if (((p_buf[0] - p[0])*(p_buf[0] - p[0]) ) +
((p_buf[1] - p[1])*(p_buf[1] - p[1])) < (p_buf[2] / 2) * (p_buf[2] / 2))
        *(sfColor *)(4 * (p_buf[1] * WIDTH + p_buf[0]) + framebuffer) = color;
}

void draw_circle_from_point(int *p, int r, sfUint8 *framebuffer, sfColor color)
{
    int *p_buf = malloc(sizeof(int) * 3);
    p_buf[2] = r;
    for (int i = p[0] - (r / 2); i < p[0] + (r / 2); ++i) {
        for (int j = p[1] - (r / 2); j < p[1] + (r / 2); ++j) {
            p_buf[0] = i;
            p_buf[1] = j;
            circle_draw_points(p_buf, framebuffer, p, color);
        }
    }
    free(p_buf);
}

void move_point_s5(int *points, int *vector)
{
    if (points[0] > (WIDTH - BALL_R / 2) - sqrt(vector[0] * vector[0])) {
        vector[0] *= -1;
    }
    if (points[0] < (BALL_R/ 2) + sqrt(vector[0] * vector[0])) {
        vector[0] *= -1;
    }
    if (points[1] >(HEIGHT - BALL_R / 2) - sqrt(vector[1] * vector[1])) {
        vector[1] *= -1;
    }
    if (points[1] < (BALL_R/ 2) + sqrt(vector[1] * vector[1])){
        vector[1] *= -1;
    }
    points[0] += vector[0];
    points[1] += vector[1];
}

void main_clock_s5 (sfUint8 *framebuffer, csfml_t graph)
{
    int p[2] = {500, 500};
    sfColor color = sfRed;
    int vector[2] = {(rand() % 50) + 20, (rand() % 50) + 20};
    while (sfRenderWindow_isOpen(graph.window)) {
        event_clock(graph.window, graph.event);
        black(framebuffer);
        rgb(&color, 1);
        move_point_s5(p, vector);
        draw_circle_from_point(p, BALL_R, framebuffer, color);
        upadate(graph.window, framebuffer, graph.sprite, graph.texture);
    }
}

int main_ss_5(void)
{
    srand(time(NULL));
    csfml_t graph = define_screen_s3(graph);
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));

    if (prepare_screen(graph.window, framebuffer, graph.sprite, graph.texture))
        return 84;
    main_clock_s5(framebuffer, graph);
    free(framebuffer);
    quit(graph.sprite, graph.texture, graph.window);
    return 0;
}