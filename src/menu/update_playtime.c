/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** update_playtime
*/

#include "rpg.h"

void update_playtime(wininf *inf)
{
    if (inf->playtime) {
        sfTexture_destroy(inf->playtime->img); free(inf->playtime->steps);
        free(inf->playtime->sps); free(inf->playtime);
    }
    char *final = my_strdup("00:00:00", malloc);
    int tmpt = sfClock_getElapsedTime(inf->play_time).microseconds / 1000000;
    int hours = tmpt / 3600; int minutes = (tmpt % 3600) / 60;
    int seconds = (tmpt % 3600) % 60;
    final[0] = hours / 10 + '0'; final[1] = hours % 10 + '0';
    final[3] = minutes / 10 + '0'; final[4] = minutes % 10 + '0';
    final[6] = seconds / 10 + '0'; final[7] = seconds % 10 + '0';
    inf->playtime = load_line(final, 15, inf, malloc);
    sfIntRect r; r.left = 0, r.top = 0; r.height = inf->playtime->height;
    r.width = inf->playtime->steps[inf->playtime->max];
    sfSprite_setTextureRect(inf->playtime->sps[0], r);
    sfVector2f old_pos = sfSprite_getPosition(inf->pause_menu->texts->data);
    sfSprite_destroy(inf->pause_menu->texts->data);
    inf->pause_menu->texts->data = inf->playtime->sps[0]; free(final);
    sfSprite_setPosition(inf->pause_menu->texts->data, old_pos);
}
