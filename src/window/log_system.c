/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** log_system
*/

#include "rpg.h"

char *print_log(wininf *inf, char *msg, va_list ap)
{
    my_fprintf_log(inf->log_file, msg, ap);
    fclose(inf->log_file);
    inf->log_file = fopen(inf->log_path, "r+");
    char * line = NULL;
    size_t len = 0;
    while (getline(&line, &len, inf->log_file) != -1);
    line[my_strlen(line) - 1] = '\0';
    return line;
}

void move_up(wininf *inf, int off)
{
    int index = 0;
    for (list *t = inf->logs; t; t = t->next, index++) {
        logline *log = t->data;
        log->target = (sfVector2f){log->target.x, log->target.y - off};
        int alived = log->alive;
        log->alive = log->alive != -1 ? index < 3 : log->alive;
        if (log->alive != alived) log->time = 0.0f;
    }
}

void add_log(wininf *inf, const float font_size, char *msg, ...)
{
    va_list ap; va_start(ap, msg);
    list *nl = malloc(sizeof(list));
    char *result = print_log(inf, msg, ap);
    dline *line = load_line(result, font_size, inf, malloc);
    logline *nlog = malloc(sizeof(logline));
    nlog->line = line; nlog->alive = 1; nlog->time = 0.0f;
    sfVector2f view = sfView_getCenter(inf->camera.view);
    nlog->target = (sfVector2f){-80.0f, 60.0f};
    nlog->oldtarget = (sfVector2f){-80.0f, 60.0f};
    sfIntRect rect = (sfIntRect){0, 0, line->steps[line->max], line->height};
    for (int i = 0; i < line->nblines; i++) {
        sfVector2f ta = (sfVector2f){nlog->target.x + view.x,
            nlog->target.y + view.y};
        sfSprite_setColor(line->sps[i], sfColor_fromRGBA(255, 255, 255, 0));
        sfSprite_setPosition(line->sps[i], ta);
        sfSprite_setTextureRect(line->sps[i], rect);
    } nl->data = nlog; nl->next = inf->logs; inf->logs = nl;
    int off = line->height + 1;
    move_up(inf, off);
}

void apply_transparency(logline *ll)
{
    dline *dl = ll->line;
    sfColor col = sfSprite_getColor(dl->sps[0]);
    if (ll->alive == 1) {
        col.a = my_lerpf(col.a, 255.0f, ll->time / 4.0f);
    } else {
        col.a = my_lerpf(col.a, 0.0f, ll->time);
        if (col.a < 1) ll->alive = -1;
    }
    for (int i = 0; i < dl->nblines; i++) {
        sfSprite_setColor(dl->sps[i], col);
    }
}
