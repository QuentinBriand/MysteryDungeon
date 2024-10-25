/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** drop_item
*/

#include "rpg.h"

dline *update_ig_choice(char *str, sfSprite *data, wininf *inf)
{
    dline *line = load_line(str, FONT_SIZE, inf, malloc);
    sfIntRect r; r.left = 0, r.top = 0;
    r.width = line->steps[line->max]; r.height = line->height;
    sfSprite_setTextureRect(line->sps[0], r);
    sfVector2f old_pos = sfSprite_getPosition(data);
    sfSprite_setPosition(line->sps[0], old_pos);
    return line;
}

int check_valid_cell(int y, wininf *inf, sfVector2i pos)
{
    for (int x = pos.x - 1; x <= pos.x + 1; x++) {
        if (x == pos.x && y == pos.y) continue;
        if (inf->dungeon.inf->map[y][x] == ' ')
            return x;
    }
    return -1;
}

sfVector2f get_valid_drop(sfVector2i pos, wininf *inf)
{
    int x = 0;
    for (int y = pos.y - 1; y <= pos.y + 1; y++) {
        x = check_valid_cell(y, inf, pos);
        if (x != -1)
            return local_to_global(x, y);
    }
    return (sfVector2f){-1, -1};
}

int check_scene(wininf *inf)
{
    if (inf->c_scene != DUNGEON) {
        if (inf->lang == ENGLISH)
            add_log(inf, FONT_SIZE, "You can't drop an item here.\n");
        else
            add_log(inf, FONT_SIZE, "Vous ne pouvez pas jeter d'objet ici.\n");
        return - 1;
    }
    return 1;
}

void drop_item(wininf *inf, player *p)
{
    if (check_scene(inf) == -1) return;
    dropped *d = malloc(sizeof(dropped));
    d->id = inf->inv->slots[inf->slot_id]->id;
    d->data = get_item_sprite(d->id, inf, p, 1); d->dropped = 1;
    char **arr = my_strtwa(inf->atlases.items[d->id], ";\n");
    push_back(&inf->d_items, d);
    add_log(inf, FONT_SIZE, "%s %s <i_l%s>\n", inf->lang ? "Vous avez jete" :
    "You dropped", arr[0], trim(my_strdup(arr[0], my_malloc), ' '));
    free(inf->ig_slots[inf->slot_id]->steps);
    inf->ig_slots[inf->slot_id] = update_ig_choice(inf->lang ? "Vide" :
    "Empty", ((choices *)inf->current_menu->selected->data)->choice, inf);
    list *tmp = inf->inventory_menu->head;
    int i = 0; for (; i < inf->slot_id; i++, tmp = tmp->next);
    sfSprite_destroy(((choices*)tmp->data)->choice);
    sfTexture_destroy(inf->inv->slots[inf->slot_id]->line->img);
    inf->inv->slots[inf->slot_id] = 0;
    ((choices *)tmp->data)->choice = inf->ig_slots[inf->slot_id]->sps[0];
    go_inv(inf, p);
}
