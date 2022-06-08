/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #define WIDTH 1920
    #define HEIGHT 1080

void event_clock(sfRenderWindow *window, sfEvent event);
void rgb(sfColor *color, int speed);
void quit (sfSprite *sprite, sfTexture *texture, sfRenderWindow *window);
void upadate(sfRenderWindow *window, sfUint8 *framebuffer,
sfSprite *sprite, sfTexture *texture);
int prepare_screen(sfRenderWindow *window, sfUint8 *framebuffer,
sfSprite *sprite, sfTexture* texture);
void move_point(int *points, int *vector);

#endif //HEADER_H_