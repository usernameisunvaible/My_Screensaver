/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

sfColor my_select_rgba(char a, char b, char c, char d)
{
    sfColor temp;

    temp.r = a;
    temp.g = b;
    temp.b = c;
    temp.a = d;
    return temp;
}