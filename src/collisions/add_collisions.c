/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** add_collisions
*/

#include "rpg.h"

void check_if_trigger(char **arr, int i, list **l)
{
    if (!my_strcmp(arr[i], "Trigger")) {
        sfVector2f pos = (sfVector2f){my_atoi(arr[i + 1]),
            my_atoi(arr[i + 2])};
        sfVector2f size = (sfVector2f){my_atoi(arr[i + 3]),
            my_atoi(arr[i + 4])};
        add_rect_col(l, pos, size);
        collision *n = ((collision*)(*l)->data);
        n->ptr = my_atoi(arr[i + 5]);
        n->auto_trigger = my_atoi(arr[i + 6]);
        sfRectangleShape_setFillColor(n->rect,
            sfColor_fromRGBA(0, 0, 255, 122));
    }
}

void add_collisions(char *str, list **l)
{
    char **arr = my_strtwa(str, ";\n\r");
    for (int i = 0; arr[i]; i++) {
        if (!my_strcmp(arr[i], "Circle")) {
            add_circle_col(l, my_atoi(arr[i + 1]), my_atoi(arr[i + 2]),
                my_atoi(arr[i + 3]));
        }
        if (!my_strcmp(arr[i], "Rect")) {
            sfVector2f pos = (sfVector2f){my_atoi(arr[i + 1]),
                my_atoi(arr[i + 2])};
            sfVector2f size = (sfVector2f){my_atoi(arr[i + 3]),
                my_atoi(arr[i + 4])};
            add_rect_col(l, pos, size);
        }
        check_if_trigger(arr, i, l);
    }
    my_free_array(arr);
}

void add_circle_col(list **l, int radius, int x, int y)
{
    list *nl = my_malloc(sizeof(list));
    collision *nc = my_malloc(sizeof(collision));
    nc->check = check_circle_col;
    nc->draw = draw_circle_col;
    nc->ptr = -1;
    nc->circle = my_circle();
    sfCircleShape_setFillColor(nc->circle, sfColor_fromRGBA(255, 0, 0, 122));
    sfCircleShape_setRadius(nc->circle, radius);
    sfCircleShape_setOrigin(nc->circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(nc->circle, (sfVector2f){x, y});
    nc->radius = radius;
    nc->pos = (sfVector2i){x, y};
    nl->data = nc;
    nl->next = *l;
    *l = nl;
}

void add_rect_col(list **l, sfVector2f pos, sfVector2f size)
{
    list *nl = my_malloc(sizeof(list));
    collision *nc = my_malloc(sizeof(collision));
    nc->check = check_rect_col;
    nc->draw = draw_rect_col;
    nc->ptr = -1;
    nc->rect = my_rectangle();
    sfRectangleShape_setFillColor(nc->rect, sfColor_fromRGBA(255, 0, 0, 122));
    sfRectangleShape_setPosition(nc->rect, (sfVector2f){pos.x, pos.y});
    sfRectangleShape_setSize(nc->rect, (sfVector2f){size.x, size.y});
    nc->size = (sfVector2i){size.x, size.y};
    nc->pos = (sfVector2i){pos.x, pos.y};
    nl->data = nc;
    nl->next = *l;
    *l = nl;
}
