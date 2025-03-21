/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** options_pointers
*/

#include "rpg.h"
#include "sounds.h"
#include "music.h"

void left_volume(wininf *inf, int current, sfVector2f old_pos, sfIntRect r)
{
    if (inf->inputs.axis.x < 0) {
        if (current == 0 || current == 1) {
            sfSound_play(inf->sounds->sounds_board[MENU_MOVE]);
            inf->pressed = 1;
            inf->volumes[current] -= inf->volumes[current] > 0 ? 5 : 0;
            inf->ig_choices[current] =
            load_line(my_itoa(inf->volumes[current]), FONT_SIZE, inf, malloc);
            r.width = inf->ig_choices[current]->
            steps[inf->ig_choices[current]->max], r.height =
            inf->ig_choices[current]->height;
            sfSprite_setTextureRect(inf->ig_choices[current]->sps[0], r);
            sfSprite_destroy(((choices *)inf->ig_options_menu->selected->data)
            ->choice);
            ((choices *)inf->ig_options_menu->selected->data)->choice = inf
            ->ig_choices[current]->sps[0];
            sfSprite_setPosition(((choices *)inf->ig_options_menu->selected
            ->data)->choice, old_pos);
            change_volume_sound_or_music(inf, current);
        }
    }
}

void right_volume(wininf *inf, int current, sfVector2f old_pos, sfIntRect r)
{
    if (inf->inputs.axis.x > 0 && (current == 0 || current == 1)) {
        sfSound_play(inf->sounds->sounds_board[MENU_MOVE]);
        inf->pressed = 1;
        inf->volumes[current] += inf->volumes[current] < 100 ? 5 : 0;
        inf->ig_choices[current] =
        load_line(my_itoa(inf->volumes[current]), FONT_SIZE, inf, malloc);
        r.width = inf->ig_choices[current]->steps[inf->ig_choices[current]
        ->max], r.height = inf->ig_choices[current]->height;
        sfSprite_setTextureRect(inf->ig_choices[current]->sps[0], r);
        sfSprite_destroy(((choices *)inf->ig_options_menu->selected->data)
        ->choice);
        ((choices *)inf->ig_options_menu->selected->data)->choice = inf
        ->ig_choices[current]->sps[0];
        sfSprite_setPosition(((choices *)inf->ig_options_menu->selected
        ->data)->choice, old_pos);
        change_volume_sound_or_music(inf, current);
    }
}

void change_volume_ig(wininf *inf)
{
    int current = ((choices *)inf->ig_options_menu->selected->data)->ptr;
    sfIntRect r; r.left = 0, r.top = 0;
    sfVector2f old_pos = sfSprite_getPosition(((choices *)inf->ig_options_menu
    ->selected->data)->choice);
    left_volume(inf, current, old_pos, r);
    right_volume(inf, current, old_pos, r);
    left_fps(inf, current, old_pos, r);
    right_fps(inf, current, old_pos, r);
}

void left_main_vol(wininf *inf)
{
    if (((choices *)inf->current_menu->selected->data)->ptr == 0) {
        inf->volumes[0] -= inf->volumes[0] > 0 ? 5 : 0;
        sfText_setString(
            ((choices *)inf->current_menu->selected->data)->choice,
            my_itoa(inf->volumes[0]));
        change_volume_sound_or_music(inf, 0);
    }
    if (((choices *)inf->current_menu->selected->data)->ptr == 1) {
        inf->volumes[1] -= inf->volumes[1] > 0 ? 5 : 0;
        sfText_setString(
            ((choices *)inf->current_menu->selected->data)->choice,
            my_itoa(inf->volumes[1]));
        change_volume_sound_or_music(inf, 1);
    }
}

void right_main_vol(wininf *inf)
{
    if (((choices *)inf->current_menu->selected->data)->ptr == 0) {
        inf->volumes[0] += inf->volumes[0] < 100 ? 5 : 0;
        sfText_setString(
            ((choices *)inf->current_menu->selected->data)->choice,
            my_itoa(inf->volumes[0]));
        change_volume_sound_or_music(inf, 0);
    }
    if (((choices *)inf->current_menu->selected->data)->ptr == 1) {
        inf->volumes[1] += inf->volumes[1] < 100 ? 5 : 0;
        sfText_setString(
            ((choices *)inf->current_menu->selected->data)->choice,
            my_itoa(inf->volumes[1]));
        change_volume_sound_or_music(inf, 1);
    }
}
