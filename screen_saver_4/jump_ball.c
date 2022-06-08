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
#include "include/my_screensaver4.h"
#include "include/header.h"

ball_t jump_ball_3(ball_t ball)
{
    if (ball.counter >= JUMP_HIGH + 2 && ball.counter < JUMP_HIGH + 7){
        ball.x1 -= TAILLE_BALL / 4;
        ball.x2 += TAILLE_BALL / 4;
        ball.y1 += TAILLE_BALL / 8;
    }
    if (ball.counter >= (JUMP_HIGH) + 9 && ball.counter < JUMP_HIGH + 14) {
        ball.x1 += TAILLE_BALL / 4;
        ball.x2 -= TAILLE_BALL / 4;
        ball.y1 -= TAILLE_BALL / 8;
    }
    return ball;
}

ball_t jump_ball_2(ball_t ball)
{
    if (ball.counter >= (JUMP_HIGH * -1) &&
ball.counter < (JUMP_HIGH * -1) + 5) {
        ball.x1 += (TAILLE_BALL / 18);
        ball.x2 -= (TAILLE_BALL / 18);
        ball.y1 -= TAILLE_BALL / 5;
    }
    if (ball.counter >= -24 && ball.counter < -4) {
        ball.x1 -= (TAILLE_BALL / 72);
        ball.x2 += (TAILLE_BALL / 72);
        ball.y2 -= TAILLE_BALL / 20;
    }
    if (ball.counter >= 4 && ball.counter < 24) {
        ball.x1 += (TAILLE_BALL / 72);
        ball.x2 -= (TAILLE_BALL / 72);
        ball.y2 += TAILLE_BALL / 20;
    }
    if (ball.counter == JUMP_HIGH + 45) {
        ball.counter = (JUMP_HIGH + 1) * -1;
    }
    return ball;
}

ball_t jump_ball(ball_t ball)
{
    if (ball.start == 1) {
        rgb(&ball.color, WAVE_SPEED);
        if (ball.counter >= JUMP_HIGH - 3 && ball.counter < JUMP_HIGH + 2) {
            ball.x1 -= (TAILLE_BALL / 18);
            ball.x2 += (TAILLE_BALL / 18);
            ball.y1 += TAILLE_BALL / 5;
        }
        if (ball.counter <= JUMP_HIGH) {
            ball.y1 += ball.counter;
            ball.y2 += ball.counter;
        }
        ball = jump_ball_2(ball);
        ball = jump_ball_3(ball);
        ++ball.counter;
    }
    return ball;
}
