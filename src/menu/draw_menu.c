/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** draw_menu
*/

#include "rpg.h"

void draw_ig_menu(wininf *inf, menuss *menu, player *p)
{
    draw_list(menu->backgrounds, inf->win);
    if (menu->choices)  {
        draw_choices(inf, menu->choices, menu->head);
        sfText *text = ((choices*)menu->selected->data)->desc;
        if (text) sfRenderWindow_drawText(inf->win, text, NULL);
    }
    if (menu->texts) draw_list(menu->texts, inf->win);
    if (menu->choices && menu->focus == 1 ) {
        if (menu->blk < 0.4f)
            sfRenderWindow_drawSprite(inf->win, menu->cursor, NULL);
        else if (menu->blk > 0.9f) menu->blk = 0;
        menu->blk += inf->time.dt;
        if (inf->waiting_key == 0) move_cursor(menu, inf, p);
    }
}

void draw_menu(wininf *inf, menuss *menu, player *p)
{
    draw_list(menu->backgrounds, inf->win);
    if (menu->choices)  {
        draw_choices(inf, menu->choices, menu->head);
        sfText *text = ((choices*)menu->selected->data)->desc;
        if (text) sfRenderWindow_drawText(inf->win, text, NULL);
    }
    if (menu->texts) draw_list(menu->texts, inf->win);
    if (menu->choices && menu->focus == 1 ) {
        if (menu->blk < 0.4f)
            sfRenderWindow_drawSprite(inf->win, menu->cursor, NULL);
        else if (menu->blk > 0.9f) menu->blk = 0;
        menu->blk += inf->time.dt;
        if (inf->waiting_key == 0) move_cursor(menu, inf, p);
    }
}
