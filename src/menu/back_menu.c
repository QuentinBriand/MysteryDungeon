/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** back_menu
*/

#include "rpg.h"

void set_backs_menu(wininf *inf)
{
    char **csvbackmenus = load_csv(rootPath"/csv/back_menus.csv");
    for (int i = 1, j = 0; i < 4; i++, j++) {
        char **back = my_strtwa(csvbackmenus[i], ";\n");
        sfIntRect rect = {my_atoi(back[1]), my_atoi(back[2]),
        my_atoi(back[3]), my_atoi(back[4])};
        inf->menuback[j] = atlas_to_sprite(rect, inf->atlases.atlas);
        sfIntRect rect2 = {0, 0, my_atoi(back[3]), my_atoi(back[4])};
        sfSprite_setTextureRect(inf->menuback[j], rect2);
        sfSprite_setScale(inf->menuback[j], (sfVector2f) {7, 7});
        sfSprite_setPosition(inf->menuback[j], (sfVector2f) {120, 0});
        my_free_array(back);
    }
    inf->back_menu = rand() % 3;
}
