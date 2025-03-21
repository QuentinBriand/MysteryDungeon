/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** load_menu_pointers
*/

#include "rpg.h"

void yes_but(wininf *inf, player *p)
{
    inf->main_menu->focus = 1;
    inf->load_menu->focus = 0;
    inf->c_scene = QUIZ;
    inf->c_menu = NONE;
    inf->current_menu = NULL;
    init_fps(inf);
}

void no_but(wininf *inf, player *p)
{
    sfSprite_setPosition(inf->load_menu->cursor, inf->load_menu->base_pos);
    inf->c_menu = NONE;
    inf->main_menu->focus = 1;
    inf->load_menu->focus = 0;
    inf->current_menu = inf->main_menu;
}
