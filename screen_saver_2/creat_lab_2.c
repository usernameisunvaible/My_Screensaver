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

void create_lab_space (int **lab)
{
    for (int i = 0; i < LEN_LAB_X; ++i) {
        lab[i] = malloc(sizeof(int) * LEN_LAB_Y);
    }
}

int make_lab_start(int i, int j, int **lab, int zone)
{
    if (i % 2 == 1 && j % 2 == 1) {
        lab[i][j] = zone;
        ++zone;
    }
    return zone;
}

int rm_wall_closer_zone(int **lab, int y, int x)
{
    if (x > 2 && lab[x - 2][y] != lab[x][y] && lab[x - 2][y] != 0) {
        lab[x - 1][y] = lab[x][y];
        return 0;
    }
    if (y > 2 && lab[x ][y - 2] != lab[x][y] && lab[x][y - 2] != 0) {
        lab[x][y - 1] = lab[x][y];
        return 0;
    }
    if (y < LEN_LAB_Y - 2 && lab[x][y + 2] != lab[x][y] && lab[x][y + 2] != 0) {
        lab[x][y + 1] = lab[x][y];
        return 0;
    }
    if (x < LEN_LAB_X - 2 && lab[x + 2][y] != lab[x][y] && lab[x + 2][y] != 0) {
        lab[x + 1][y] = lab[x][y];
        return 0;
    }
}

void remove_random(int **lab)
{
    int random_case[2] = {0, 0};

    while (lab[random_case[0]] [random_case[1]] == 0) {
        random_case[0] = (rand() % LEN_LAB_X - 1) + 1;
        random_case[1] = (rand() % LEN_LAB_Y - 1) + 1;
    }
    rm_wall_closer_zone(lab, random_case[1], random_case[0]);
}

void clock_unification(int **lab, int i)
{
    for (int j = 1; j < LEN_LAB_Y - 1; ++j) {
        if (i % 2 == 1 && j % 2 == 1)
            unification(lab, i, j, lab[i][j]);
    }
}