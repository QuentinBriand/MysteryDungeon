/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** manage_help
*/

#include "rpg.h"

void manage_help(void)
{
    char **help = load_csv("./txt/help.txt");
    for (int i = 0; help[i] != NULL; i++)
        my_putstr(help[i]);
    my_malloc(0);   
}
