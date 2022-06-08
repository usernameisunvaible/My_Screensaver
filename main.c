/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/main.h"

void wich_one(char *c)
{
    if (c[0] == '1')
        main_ss_1();
    if (c[0] == '2')
        main_ss_2();
    if (c[0] == '3')
        main_ss_3();
    if (c[0] == '4')
        main_ss_4();
    if (c[0] == '5')
        main_ss_5();
}

int main(int argc, char **argv)
{
    if (argc > 1 && argc < 3)
        wich_one(argv[1]);
    return 0;
}