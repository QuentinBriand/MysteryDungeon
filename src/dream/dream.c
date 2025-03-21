/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** dream
*/

#include "dream.h"
#include "ditto.h"

void clock_dream(wininf *inf, dream_a *dream)
{
    if (inf->time.ditto_anim > 0.05f) {
        if (dream->b_dream[1].rect.top >= 192)
            dream->b_dream[1].rect.top = 0;
        else
            dream->b_dream[1].rect.top += 1;
        if (dream->b_dream[2].rect.top <= 0) dream->b_dream[2].rect.top = 192;
        else dream->b_dream[2].rect.top -= 1;
        inf->time.ditto_anim = 0.0f;
    }
    if (inf->time.ditto_anim2 > 0.05f) {
        dream->color += 1;
        if (dream->color >= 360) dream->color = 0;
        sfColor changecolor = my_hsvtorgb(dream->color, 100, 100);
        for (int i = 0; i < 3; i++)
            sfSprite_setColor(inf->dream->b_dream[i].sprite, changecolor);
        inf->time.ditto_anim2 = 0.0f;
    }
}

void draw_dream(wininf *inf)
{
    if (inf->dream == NULL) inf->dream = create_dream(inf);
    if (inf->dream->plan != DELETEDREAM) {
        if (sfMusic_getStatus(inf->dream->music) != sfPlaying)
            sfMusic_play(inf->dream->music);
        clock_dream(inf, inf->dream);
        for (int i = 0; i < 3; i++)
            display_ele(inf->win, inf->dream->b_dream[i]);
    }
    if (inf->dream->plan == DELETEDREAM) sfMusic_stop(inf->dream->music);
}
