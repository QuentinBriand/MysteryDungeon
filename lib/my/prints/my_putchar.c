/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Putchar
*/

#include "../printf.h"

int my_putchar_disp(FILE *file, char *c)
{
    fwrite(c, 1, sizeof(char), file);
    return 0;
}
