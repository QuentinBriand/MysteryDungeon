/*
** EPITECH PROJECT, 2021
** my_put_specias
** File description:
** Put special
*/

#include "../printf.h"

int my_put_specialarg(char str)
{
    char backslash = '\\';
    if (str < 8) {
        my_putchar_disp(0, &backslash);
        my_putstrprintf(0, "00");
        my_putnbr_oct(str);
    }
    if (str >= 8 && str < 32) {
        my_putchar_disp(0, &backslash);
        my_putstrprintf(0, "0");
        my_putnbr_oct(str);
    }
    if (str == 127) {
        my_putchar_disp(0, &backslash);
        my_putnbr_oct(str);
    }
    return 0;
}

int my_put_special(char *str)
{
    for (int counter = 0; str[counter] != '\0'; counter++) {
        if (str[counter] < 32 || str[counter] == 127) {
            my_put_specialarg(str[counter]);
        } else {
            my_putchar(str[counter]);
        }
    }
    return 0;
}
