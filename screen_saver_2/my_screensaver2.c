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

int create_new_lab(int **lab, int fadeout, int *beeg)
{
    if (fadeout == 257) {
        *beeg = create_lab(lab);
        --fadeout;
    }
    return fadeout;
}

counter_t define_counters (counter_t counter)
{
    counter.max = 0;
    counter.min = -1024;
    counter.fadeout = 0;
    return counter;
}

csfml_t define_screen (csfml_t graph)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    graph.window = sfRenderWindow_create(mode, "screensaver_1",
    sfResize | sfClose | sfFullscreen, NULL);
    graph.texture = sfTexture_create(WIDTH, HEIGHT);
    graph.sprite = sfSprite_create();
    return graph;
}

void main_clock(csfml_t graph, counter_t counter, int **lab,
sfUint8 *framebuffer)
{
    while (sfRenderWindow_isOpen(graph.window)) {
        event_clock(graph.window, graph.event);
        if (counter.max < counter.beeg && counter.fadeout == 0) {
            counter.max += VITESSE_DRAW;
            draw_lab(framebuffer, lab, (int)counter.max);
        }
        counter.max = refresh_lab_resolve(counter.max, counter.beeg, lab);
        if (counter.min < -2 && counter.max == counter.beeg + VITESSE_DRAW * 2){
            counter.min += VITESSE_DRAW;
            draw_lab(framebuffer, lab, (int)counter.min);
            lab[0][1] = lab[1][1] + 1;
        }
        counter.fadeout = create_new_lab(lab, counter.fadeout, &counter.beeg);
        if ((int) counter.min > lab[0][1] || (int) counter.min > -2 ) {
            counter = define_counters(counter);
            counter.fadeout = 257;
        }
        counter.fadeout = fadeout_apply(counter.fadeout, lab, framebuffer);
        upadate(graph.window, framebuffer, graph.sprite, graph.texture);
    }
}

int main_ss_2(void)
{
    srand(time(NULL));
    csfml_t graph = define_screen(graph);
    int **lab = malloc(sizeof(int *) * LEN_LAB_X);
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    counter_t counter = define_counters(counter);

    create_lab_space(lab);
    counter.beeg = create_lab(lab);
    if (prepare_screen(graph.window, framebuffer, graph.sprite, graph.texture))
        return 1;
    main_clock(graph, counter, lab, framebuffer);
    for (int i = 0; i < LEN_LAB_X; ++i)
        free(lab[i]);
    free(lab);
    free(framebuffer);
    quit(graph.sprite, graph.texture, graph.window);
    return 0;
}
