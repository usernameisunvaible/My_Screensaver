    /*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SCREEN_SAVER_5
    #define SCREEN_SAVER_5

    #define WIDTH 1920
    #define HEIGHT 1080

typedef struct csfml_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
}csfml_t;

csfml_t define_screen_s3 (csfml_t graph);
void black(sfUint8 *framebuffer);
sfColor my_select_rgba(char a, char b, char c, char d);

#endif //SCREEN_SAVER_5