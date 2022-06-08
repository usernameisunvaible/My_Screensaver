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
#include "include/header.h"
#include "include/my_screensaver2.h"

void event_clock(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed && sfKeyEscape == event.key.code)
            sfRenderWindow_close(window);
    }
}

void rgb(sfColor *color, int speed)
{
    --speed;
    if (color -> r >= 255 - speed && color -> b <= speed)
        color ->g += speed + 1;
    if (color -> g >= 255 - speed && color -> b <= speed)
        color ->r -= speed + 1;
    if (color -> g >= 255 - speed && color -> r <= speed)
        color ->b += speed + 1;
    if (color -> b >= 255 - speed && color -> r <= speed)
        color ->g -= speed + 1;
    if (color -> b >= 255 - speed && color -> g <= speed)
        color ->r += speed + 1;
    if (color -> r >= 255 - speed && color -> g <= speed)
        color ->b -= speed + 1;
}

void quit (sfSprite *sprite, sfTexture *texture, sfRenderWindow *window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

void upadate(sfRenderWindow *window, sfUint8 *framebuffer,
sfSprite *sprite, sfTexture *texture)
{
    sfRenderWindow_clear(window, sfBlack);
    sfTexture_updateFromPixels(texture, framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int prepare_screen(sfRenderWindow *window, sfUint8 *framebuffer,
sfSprite *sprite, sfTexture* texture)
{
    if (!window || !framebuffer || !texture || !sprite)
        return 1;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return 0;
}