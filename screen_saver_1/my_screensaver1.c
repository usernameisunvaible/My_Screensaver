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
#include "include/my_screensaver1.h"
#include "include/header.h"

void draw_line(sfUint8 *framebuffer, int *p1, int *p2, sfColor color)
{
    int p_x = 0;
    int p_y = 0;
    int tab[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int j = 0; j < 5 ; ++j) {
        for (float i = 0; i < 1; i += 0.0001) {
            p_x = p1[0] + tab[j][0] + (p2[0] +
tab[j][0] - p1[0] + tab[j][0]) * i;
            p_y = p1[1] + tab[j][1] + (p2[1] +
tab[j][1] - p1[1] + tab[j][1]) * i;
            *(sfColor *)(4 * (p_y * WIDTH + p_x) + framebuffer) = color;
        }
    }
}

void fade_out(sfUint8 *framebuffer, sfColor color )
{
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j)
            (*(sfColor *)(4 * (j * WIDTH + i) + framebuffer)).a -= 6;
    }
}

void draw_and_move(int **points, int **vectors, sfUint8 *framebuffer,
sfColor color)
{
    for (int i = 0; i < NBR_PTS; i++){
        for (int j = 0; j < NBR_PTS; j++) {
            draw_line(framebuffer, points[i], points[j], color);
        }
        move_point(points[i], vectors[i]);
    }
}


void put_pixel(sfVector2f p, sfColor color, sfUint8 *framebuffer)
{
    unsigned int coord = (p.y * WIDTH + p.x) * 4;

    if (coord < HEIGHT * WIDTH * 4 && coord >= 0) {
    //     framebuffer[coord] = color.r;
    //     framebuffer[coord + 1] = color.g;
    //     framebuffer[coord + 2] = color.b;
    //     framebuffer[coord + 3] = color.a;
    // }
        *(sfColor *)(coord + framebuffer) = color;
    }
}

int open_window(int **points, int **vectors)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "screensaver_1",
    sfResize | sfClose | sfFullscreen, NULL);
    sfEvent event;
    sfTexture* texture = sfTexture_create(WIDTH, HEIGHT);
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    sfSprite *sprite = sfSprite_create();
    sfColor color = sfRed;
    sfVector2f p1;
    if (prepare_screen(window, framebuffer, sprite, texture))
        return 1;
    while (sfRenderWindow_isOpen(window)) {
        
        rgb(&color, 1);
        event_clock(window, event);
        fade_out(framebuffer, color);
        draw_and_move(points, vectors, framebuffer, color);
        upadate(window, framebuffer, sprite, texture);
    }
    free(framebuffer);
    quit(sprite, texture, window);
    return 0;
}

int main_ss_1(void)
{
    int *points[NBR_PTS];
    int *vectors[NBR_PTS];

    srand(time(NULL));
    for (int i = 0; i < NBR_PTS; ++i){
        points[i] = malloc(sizeof(int) * 2);
        vectors[i] = malloc(sizeof(int) * 2);
        vectors[i] [0] = rand()%2 + 1;
        vectors[i] [1] = rand()%2 + 1;
        points[i][0] = rand()%WIDTH;
        points[i][1] = rand()%HEIGHT;
    }
    return open_window(points, vectors);
}