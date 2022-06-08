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

void draw_rect_s4(ball_t p, sfUint8 *framebuffer, sfColor color)
{
    for (int i = p.x1 ; i < p.x2; i++){
        for (int j = p.y1; j < p.y2; j++) {
            *(sfColor *)(4 * (j * WIDTH + i) + framebuffer) = color;
        }
    }
}

void black(sfUint8 *framebuffer)
{
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++) {
            *(sfColor *)(4 * (i * WIDTH + j) + framebuffer) = sfBlack;
        }
    }
}

int wave_jump (ball_t *balls, int wave_count)
{
    for (int i = 0; i < NBR_BALLS; ++i) {
        if (balls[i].x1 <= wave_count)
            balls[i].start = 1;
    }
    return wave_count + WAVE_SPEED;
}

void main_clock_s4 (sfUint8 *framebuffer, csfml_t graph)
{
    ball_t *balls = malloc(sizeof(ball_t) * NBR_BALLS);
    int wave_count = 0;

    create_balls(balls);
    while (sfRenderWindow_isOpen(graph.window)) {
        event_clock(graph.window, graph.event);
        black(framebuffer);
        if (wave_count >= 0 && wave_count <= WIDTH)
            wave_count = wave_jump(balls, wave_count);
        else
            wave_count = -1;
        for (int i = 0; i < NBR_BALLS; ++i) {
            draw_rect_s4(balls[i], framebuffer, balls[i].color);
            balls[i] = jump_ball(balls[i]);
        }
        upadate(graph.window, framebuffer, graph.sprite, graph.texture);
    }
    free(balls);
}

int main_ss_4(void)
{
    srand(time(NULL));
    csfml_t graph = define_screen_s4(graph);
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));

    if (prepare_screen(graph.window, framebuffer, graph.sprite, graph.texture))
        return 84;
    main_clock_s4(framebuffer, graph);
    free(framebuffer);
    quit(graph.sprite, graph.texture, graph.window);
    return 0;
}