/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** Prints a string and returns 0
*/

#include "my.h"

int my_putnbr_base(int nbr, char *base)
{
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr >= my_strlen(base) - 1)
        my_putnbr_base(nbr / my_strlen(base), base);
    my_putchar(base[nbr % my_strlen(base)]);
    return (nbr);
}

int check_ascii(char *str, int i)
{
    if (str[i] < 14) {
        my_putchar('0');
    }
    return 0;
}

int my_showstr(char *str)
{
    int i;
    i = 0;
    while (str[i]) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            check_ascii(str, i);
            my_putnbr_base((str[i]), "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
        i = i + 1;
    }
    return (0);
}
