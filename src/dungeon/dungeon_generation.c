/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** generation
*/

#include "rpg.h"

sfImage *get_dungeon_image(sfImage *atlas, int id)
{
    sfIntRect r = (sfIntRect){5992 + 144 * id, 0, 144, 1128};
    sfTexture *tex = sfTexture_createFromImage(atlas, &r);
    sfImage *cdungeon = sfTexture_copyToImage(tex);
    sfTexture_destroy(tex);
    return cdungeon;
}

int print_next_log(wininf *win)
{
    if (win->dungeon.floor > 5) {
        if (!win->dungeon.ended) {
            win->c_scene = DITTO;
            add_log(win, FONT_SIZE, "You finished the dungeon !\n");
            add_log(win, FONT_SIZE, "Well done :DD\n");
        }
        win->dungeon.time += win->time.dt;
        win->dungeon.ended = 1;
        if (win->dungeon.time > 5.0f) {
            win->dungeon.next = 1; win->dungeon.in = 0;
            win->transition = 1;
            win->next_pos = (sfVector2f){520.0f, 320.0f};
            win->change_scene = 1;
            win->next_scene = VILLAGE;
        }
        return 1;
    } else {
        add_log(win, FONT_SIZE, "Floor %d\n", win->dungeon.floor);
    }
    return 0;
}

void reroll_dungeon(wininf *win, player *p)
{
    if (win->change_scene != -1) return;
    for (list *t = win->dungeon.enemies; t;) {
        list *temp = t; t = t->next;
        player *enemy = temp->data;
        free(enemy); free(temp); temp = 0;
    }
    win->dungeon.enemies = 0;
    if (print_next_log(win)) return;
    win->dungeon.floor++; create_dungeon(win, win->dungeon.id);
    p->nextpos = win->dungeon.inf->starting_pos;
    sfSprite_setPosition(p->test, p->nextpos);
    sfView_setCenter(win->camera.view, p->nextpos);
}

void free_map_inf(map_inf *inf)
{
    for (int i = 0; inf->map[i]; i++) free(inf->map[i]);
    free(inf->map);
    for (int i = 0; i < inf->nbr_rooms; i++)
        free(inf->rooms[i]);
    free(inf->rooms);
    sfSprite_destroy(inf->sp);
    sfSprite_destroy(inf->stairs);
    free(inf);
}

void create_dungeon(wininf *win, int id)
{
    sfImage *img = get_dungeon_image(win->atlases.atlas, id);
    if (win->dungeon.inf) free_map_inf(win->dungeon.inf);
    win->dungeon.inf = generate_map(3, img, win->atlases.atlas);
    sfImage_destroy(img);
    treat_dungeon_sync(win, id); win->dungeon.in = 1;
    map_inf *i = win->dungeon.inf;
    sfVector2i pos = global_to_local(i->starting_pos);
    pos.x += 3;
    for (int o = 0; o < 10; o++) {
        sfVector2f rdmpos = get_random_position(i->rooms, i->nbr_rooms);
        if (distance(rdmpos, i->starting_pos) < 40) {
            o--;
            continue;
        }
        create_enemy(win, &win->dungeon, global_to_local(rdmpos));
    }
}
