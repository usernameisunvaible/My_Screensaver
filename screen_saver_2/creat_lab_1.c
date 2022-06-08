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

int create_lab (int **lab)
{
    for (int i = 0; i < LEN_LAB_X; ++i) {
        for (int j = 0; j < LEN_LAB_Y; ++j) {
            lab[i][j] = 0;
        }
    }
    generer_lab(lab);
    for (int i = 0; i < LEN_LAB_X; ++i) {
        for (int j = 0; j < LEN_LAB_Y; ++j) {
            lab[i][j] = replace_number(lab[i][j]);
        }
    }
    recursion_solve(lab, 0, 1, 3);
    return biggest_number(lab);
}

int detect_zone(int current, int *nbr)
{
    if (current != 0 && *nbr == 0) {
        *nbr = current;
        return 0;
    }
    if (current != 0 && current != *nbr)
        return 2;
    return 0;
}
int nbr_zone (int **lab)
{
    int nbr = 0;
    int count = 0;
    for (int i = 0; i < LEN_LAB_X; ++i) {
        for (int j = 0; j < LEN_LAB_Y; ++j) {
            count += detect_zone(lab[i][j], &nbr);
        }
    }
    return count;
}

void unification(int **lab, int i, int j, int current)
{
    if (i > 1 && lab[i - 1][j] != 0 && lab[i - 1][j] != current) {
        lab[i - 1][j] = current;
        unification(lab, i - 1, j, current);
    }
    if (i < LEN_LAB_X - 1 && lab[i + 1][j] != 0 && lab[i + 1][j] != current) {
        lab[i + 1][j] = current;
        unification(lab, i + 1, j, current);
    }
    if (j > 1 && lab[i][j - 1] != 0 && lab[i][j - 1] != current) {
        lab[i][j - 1] = current;
        unification(lab, i, j - 1, current);
    }
    if (j < LEN_LAB_Y - 1 && lab[i][j + 1] != 0 && lab[i][j + 1] != current) {
        lab[i][j + 1] = current;
        unification(lab, i, j + 1, current);
    }
}

void generer_lab(int **lab)
{
    int zone = 2;

    for (int i = 0; i < LEN_LAB_X; ++i) {
        for (int j = 0; j < LEN_LAB_Y; ++j) {
            zone = make_lab_start(i, j, lab, zone);
        }
    }
    while (nbr_zone(lab) > 1) {
        remove_random(lab);
        for (int i = 1; i < LEN_LAB_X - 1; ++i) {
            clock_unification(lab, i);
        }
    }
    lab[0][1] = 1;
    lab[LEN_LAB_X - 1][LEN_LAB_Y - 2] = 1;
}