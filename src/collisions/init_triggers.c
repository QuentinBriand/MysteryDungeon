/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** init_triggers
*/

#include "rpg.h"
#include "dungeon.h"

void create_triggers(wininf *inf)
{
    inf->triggers[0] = homeext_to_village;
    inf->triggers[1] = homeext_to_homeint;
    inf->triggers[2] = ta_mere;
    inf->triggers[3] = sleep_and_save;
    inf->triggers[4] = interact_pnj;
    inf->triggers[5] = village_to_bekipan;
    inf->triggers[6] = village_to_dittoland;
    inf->triggers[7] = village_to_dojo;
    inf->triggers[8] = generate_random_dungeon;
    inf->triggers[9] = interact_pnj_quest;
}

void ta_mere(wininf *win, player *p)
{
    sfVector2f mid = (sfVector2f){520.0f, 320.0f};
    win->next_scene = VILLAGE;
    win->next_pos = mid;
    win->transition = 1;
    win->change_scene = 1;
    if (win->net->is_multi) {
        add_ord(SETPOS, &win->next_pos, sizeof(sfVector2f), win->net->packet);
        add_ord(CHANGE_SCENE, &win->next_scene, sizeof(int), win->net->packet);
    }
}

void generate_random_dungeon(wininf *win, player *p)
{
    int id = rand() % 12;
    win->dungeon.id = id;
    win->dungeon.in = 0; win->dungeon.enemies = 0; win->dungeon.floor = 1;
    win->dungeon.ended = 0; win->dungeon.next = 0;
    win->dungeon.time = 0.0f;
    create_dungeon(win, id);
    p->can_move = 1;
    sfSprite_setPosition(p->test, win->dungeon.inf->starting_pos);
    p->nextpos = win->dungeon.inf->starting_pos;
    sfView_setCenter(win->camera.view,  win->dungeon.inf->starting_pos);
    win->next_scene = DUNGEON;
    win->next_pos = win->dungeon.inf->starting_pos;
    win->transition = 1;
    win->change_scene = 1;
    if (win->net->is_multi) {
        add_ord(SETPOS, &win->next_pos, sizeof(sfVector2f), win->net->packet);
        add_ord(CHANGE_SCENE, &win->next_scene, sizeof(int), win->net->packet);
    }
}

void interact_pnj(wininf *win, player *p)
{
    float min = 200.f; pnj *closest = 0;
    list *l = win->scenes[win->c_scene].pnjs;
    for (list *t = l; t; t = t->next) {
        pnj *cp = t->data;
        float cmn = manhattan_distance(sfSprite_getPosition(p->test), cp->pos);
        if (cmn < min) {
            min = cmn; closest = cp;
        }
    }
    sfVector2f poubelle = sfView_getCenter(win->camera.view);
    poubelle.y += 45.0f; win->interacting = 1;
    sfSprite_setPosition(win->ui.background, poubelle);
    if (!win->ui.dialog) {
        win->ui.dialog = create_dialog_list(win, closest->dialog, poubelle);
    } else {
        update_rects_dialog(win);
    }
}

void sleep_and_save(wininf *win, player *p)
{
    add_log(win, FONT_SIZE, "Saving...\n");
    win->change_scene = 0;
    win->transition = 1;
}
