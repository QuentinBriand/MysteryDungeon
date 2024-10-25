/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display str
*/

#include "my.h"

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
