/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SCREEN_SAVER_3
    #define SCREEN_SAVER_3

#define WIDTH 1920
#define HEIGHT 1080
#define LEN 200
#define RGB_SPEED 5

typedef struct csfml_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
}csfml_t;

sfColor my_select_rgba(char a, char b, char c, char d);

#endif //SCREEN_SAVER_3