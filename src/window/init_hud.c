/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** init_hud
*/

#include "rpg.h"

void init_hud(wininf *inf)
{
    for (int i = 0; i < 4; i++)
        inf->ui.hud[i] = my_sprite();
    sfTexture *tex = sfTexture_createFromImage(inf->atlases.atlas,
    &((sfIntRect){820, 1157, 10, 8}));
    sfSprite_setTexture(inf->ui.hud[0], tex, sfTrue);
    tex = sfTexture_createFromImage(inf->atlases.atlas,
    &((sfIntRect){831, 1157, 13, 8}));
    sfSprite_setTexture(inf->ui.hud[1], tex, sfTrue);
    tex = sfTexture_createFromImage(inf->atlases.atlas,
    &((sfIntRect){844, 1157, 6, 8}));
    sfSprite_setTexture(inf->ui.hud[2], tex, sfTrue);
    tex = sfTexture_createFromImage(inf->atlases.atlas,
    &((sfIntRect){820, 1166, 30, 6}));
    sfSprite_setTexture(inf->ui.hud[3], tex, sfTrue);
    for (int i = 0; i < 2; i++) {
        inf->ui.hp[i] = sfText_create();
        sfText_setCharacterSize(inf->ui.hp[i], 50);
        sfText_setScale(inf->ui.hp[i], (sfVector2f){0.25, 0.25});
        sfText_setFont(inf->ui.hp[i], inf->ui.font);
        sfText_setString(inf->ui.hp[i], "HP");
    }
}
