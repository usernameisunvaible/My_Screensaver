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
#include "include/my_screensaver1.h"
#include "include/header.h"

void move_point(int *points, int *vector)
{
    if (points[0] >= WIDTH - DIST_REBOND || points[0] <= DIST_REBOND) {
        vector[0] *= -1;
    }
    if (points[1] >= HEIGHT - DIST_REBOND || points[1] <= DIST_REBOND) {
        vector[1] *= -1;
    }
    points[0] += vector[0] / 3 + vector[0] %3;
    points[1] += vector[1] / 3 + vector[1] %3;
}