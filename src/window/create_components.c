/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_compoments
*/

#include "rpg.h"

components create_all_components(int ac, char **argv)
{
    components cps = {0};
    cps.inf = create_window_infos(ac, argv);
    cps.pla = init_player(cps.inf, cps.inf.settings->pokemon);
    cps.pla->equip_bg_slot = generate_textbox((sfVector2i) {35, 35},
    cps.inf.atlases.atlas);
    cps.inf.camera.target = cps.pla->test;
    return cps;
}
