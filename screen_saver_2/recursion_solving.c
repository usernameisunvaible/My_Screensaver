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

void recursion_solve_p2(int **lab, int x, int y, int dist)
{
    if (x < LEN_LAB_X - 1) {
        if (lab[x + 1][y] == -1 || dist < lab[x + 1][y]) {
            lab[x + 1][y] = dist;
            recursion_solve(lab, x + 1, y, dist + 1);
        }
    }
    if (y < LEN_LAB_Y -1) {
        if (lab[x][y + 1] == -1 || dist < lab[x][y + 1]) {
            lab[x][y + 1] = dist;
            recursion_solve(lab, x, y + 1, dist + 1);
        }
    }
}

void recursion_solve(int **lab, int x, int y, int dist)
{
    if (x > 0) {
        if (lab[x - 1][y] == -1 || dist < lab[x - 1][y]) {
            lab[x - 1][y] = dist;
            recursion_solve(lab, x - 1, y, dist + 1);
        }
    }
    if (y > 0) {
        if (lab[x][y - 1] == -1 || dist < lab[x][y - 1]) {
            lab[x][y - 1] = dist;
            recursion_solve(lab, x, y - 1, dist + 1);
        }
    }
    recursion_solve_p2(lab, x, y, dist);
}

void recursion_line_p2(int **lab, int *x_y, int current, int nbr)
{
    if (x_y[1] > 0 && lab[x_y[0]][x_y[1] - 1] < current &&
lab[x_y[0]][x_y[1] - 1] > 0) {
        lab[x_y[0]][x_y[1]] = nbr;
        --x_y[1];
        recursion_line(lab, x_y, current, nbr + 1);
    }
    if (x_y[1] < LEN_LAB_Y - 1 && lab[x_y[0]][x_y[1] + 1] < current &&
lab[x_y[0]][x_y[1] + 1] > 0) {
        lab[x_y[0]][x_y[1]] = nbr;
        ++x_y[1];
        recursion_line(lab, x_y, current, nbr + 1);
    }
}

void recursion_line(int **lab, int *x_y, int current, int nbr)
{
    current = lab[x_y[0]][x_y[1]];
    if (x_y[0] > 0 && lab[x_y[0] - 1][x_y[1]] < current &&
        lab[x_y[0] - 1][x_y[1]] > 0) {
        lab[x_y[0]][x_y[1]] = nbr;
        --x_y[0];
        recursion_line(lab, x_y, current, nbr + 1);
    }
    if (x_y[0] < LEN_LAB_X -2 && lab[x_y[0] + 1][x_y[1]] < current &&
lab[x_y[0] + 1][x_y[1]] > 0) {
        lab[x_y[0]][x_y[1]] = nbr;
        ++x_y[0];
        recursion_line(lab, x_y , current, nbr + 1);
    }
    recursion_line_p2(lab, x_y, current, nbr);
}
