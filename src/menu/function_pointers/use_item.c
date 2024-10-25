/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** use_item
*/

#include "rpg.h"

void go_use_item(wininf *inf, player *p)
{
    inf->slot_id = ((choices *)inf->current_menu->selected->data)->ptr;
    if (inf->inv->slots[inf->slot_id] == 0) return;
    inf->current_menu->focus = 0;
    inf->current_menu = inf->use_item_menu;
    inf->c_menu = USE_ITEM;
    inf->current_menu->focus = 1;
    inf->use_item_menu->press = inf->pressed;
}

void use_item(wininf *inf, player *p)
{
    char **arr = my_strtwa(inf->atlases.items[inf->inv->slots[inf->slot_id]
    ->id], ";\n");
    if (my_strcmp(arr[1], "REGEN") == 0) {
        p->st.health += my_atoi(arr[2]);
        p->st.health = p->st.health > p->st.max_health ?
        p->st.max_health : p->st.health;
        add_log(inf, COMBAT_FONT_SIZE, "Healed by: %d, now at %d\n", my_atoi(arr[2]),
            p->st.health);
    }
    if (my_strcmp(arr[1], "ATK") == 0) p->st.atk_boost += my_atoi(arr[2]);
    if (my_strcmp(arr[1], "DEF") == 0) p->st.def_boost += my_atoi(arr[2]);
    if (my_strcmp(arr[1], "HP") == 0)
        p->st.max_health_boost += my_atoi(arr[2]);
    if (my_strcmp(arr[1], "SPD") == 0) p->st.speed_boost += my_atoi(arr[2]);
}
