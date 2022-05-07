/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** coordinate
*/

#include "rpg.h"
#include "dungeon.h"

sfVector2f **get_random_position(sfIntRect **rooms, int count, char ***map)
{
    int rdm = (rand() % count);
    sfVector2f **array = malloc(2 * sizeof(sfVector2f*));
    sfVector2f *start_posf = malloc(sizeof(sfVector2f));
    sfVector2f *last_posf = malloc(sizeof(sfVector2f));
    *start_posf = local_to_global(0, 0);
    *last_posf = local_to_global(1, 0);
    (*map)[0][1] = 'F';
    array[0] = start_posf;
    array[1] = last_posf;
    return array;
}

sfVector2f local_to_global(int x, int y)
{
    return (sfVector2f){x * 24.0f + 12.0f, y * 24.0f + 12.0f};
}

sfVector2i global_to_local(sfVector2f p) {
    int a = p.x / 24.0f;
    int b = p.y / 24.0f;
    return (sfVector2i){a, b};
}

int get_current_roomlo(sfVector2i pos, map_inf *inf)
{
    for (int i = 0; inf->rooms[i]; i++) {
        sfIntRect *rect = inf->rooms[i];
        if (sfIntRect_contains(rect, pos.x, pos.y)) {
            return i;
        }
    }
    return -1;
}

int get_current_room(sfVector2f pos, map_inf *inf)
{
    sfVector2i lpos = global_to_local(pos);
    return get_current_roomlo(lpos, inf);
}

void get_closest_exitx(sfIntRect cr, map_inf *i, sfVector2f *dy, sfIntRect *e)
{
    for (int x = cr.left; x < cr.left + cr.width; x++) {
        if (i->map[(int)dy->y][x] != 'E') continue;
        sfVector2f exi = (sfVector2f){x, dy->y};
        float nds = distance(exi, (sfVector2f){e->width, e->height});
        if (dy->x > nds) {
            dy->x = nds;
            sfVector2i nd = (sfVector2i){x, dy->y};
            e->left = nd.x;
            e->top = nd.y;
        }
    }
}

sfVector2i get_closest_exit(int r, sfVector2f t, map_inf *inf)
{
    if (r == -1) return (sfVector2i){0, 0};
    sfIntRect croom = *(inf->rooms[r]);
    sfVector2f dsty = (sfVector2f){MAP_SIZE * 2, 0};
    sfVector2i lt = global_to_local(t);
    sfIntRect endplt = (sfIntRect){0, 0, lt.x, lt.y};
    for (int y = croom.top; y < croom.top + croom.height + 1; y++) {
        dsty.y = (float)y;
        get_closest_exitx(croom, inf, &dsty, &endplt);
    }
    return (sfVector2i){endplt.left, endplt.top};
}
