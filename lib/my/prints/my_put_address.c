/*
** EPITECH PROJECT, 2021
** my_put_address
** File description:
** Put the address of the entry
*/

#include "../printf.h"

int my_putnbr_hexaaddress(unsigned int nbr)
{
    char *base = "0123456789abcdef";
    int size = 0;
    unsigned int mod = nbr;
    while (base[size] != '\0')
        size++;
    if (size <= 1)
        return (nbr);
    mod %= size;
    if (mod < 0)
        mod = -mod;
    if (nbr / size == 0) {
        if (nbr < 0)
            my_putchar('-');
        my_putchar(base[mod]);
        return (nbr);
    }
    my_putnbr_hexalow(nbr / size);
    my_putchar(base[mod]);
    return (nbr);
}

int my_put_address(unsigned int str)
{
    my_putchar('0');
    my_putchar('x');
    return my_putnbr_hexaaddress(str);
}
