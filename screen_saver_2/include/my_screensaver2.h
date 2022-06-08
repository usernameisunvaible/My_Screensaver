/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SCREEN_SAVER_2
    #define SCREEN_SAVER_2

    #define WIDTH 1920
    #define HEIGHT 1080
    #define LEN_LAB_X 107
    #define LEN_LAB_Y 191
    #define TAILLE_BLOCS 10
    #define VITESSE_DRAW 1

void recursion_line(int **lab, int *x_y, int current, int nbr);
void recursion_solve(int **lab, int x, int y, int dist);
void create_lab_space (int **lab);
int fadeout_apply(int fadeout, int **lab, sfUint8 *framebuffer);
float refresh_lab_resolve(float max, int beeg, int **lab);
void draw_lab(sfUint8 *framebuffer, int **lab, int max);
int create_lab (int **lab);
sfColor color_lab(int nbr, int max);
sfColor line_drawing(int nbr, int min);
void draw_rect(int *p1, int *p2, sfUint8 *framebuffer, sfColor color);
void remove_random(int **lab);
int make_lab_start(int i, int j, int **lab, int zone);
void generer_lab (int **lab);
int biggest_number(int **lab);
void clock_unification(int **lab, int i);
void unification(int **lab, int i, int j, int current);
int replace_number (int labij);
sfColor my_select_rgba(char a, char b, char c, char d);

typedef struct counter_s {
    float max;
    float min;
    int beeg;
    int fadeout;
} counter_t;

typedef struct csfml_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
}csfml_t;

#endif //SCREEN_SAVER_2