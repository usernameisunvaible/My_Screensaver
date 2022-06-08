    /*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SCREEN_SAVER_4
    #define SCREEN_SAVER_4

#define WIDTH 1920
#define HEIGHT 1080
#define TAILLE_BALL 72
#define JUMP_HIGH 40
#define NBR_BALLS 1
#define WAVE_SPEED 2

typedef struct csfml_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
}csfml_t;

typedef struct ball_s {
    int x1;
    int y1;
    int x2;
    int y2;
    int counter;
    sfColor color;
    int start;
}ball_t;

csfml_t define_screen_s4 (csfml_t graph);
void create_balls(ball_t *balls);
ball_t jump_ball(ball_t ball);
sfColor my_select_rgba(char a, char b, char c, char d);
#endif //SCREEN_SAVER_4