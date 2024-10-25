/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *src, void *(ptr)(size_t t))
{
    if (!src) return 0;
    int length = my_strlen(src);
    char *out = ptr(sizeof(src) * (length + 2));

    my_strcpy(out, src);
    return out;
}
