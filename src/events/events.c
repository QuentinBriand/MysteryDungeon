/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** events
*/

#include "rpg.h"
#include "quiz.h"
#include "infos.h"
#include "intro.h"
#include "inputs.h"

void check_back(wininf *inf, player *p)
{
    if (inf->inputs.axis.x == 0 || inf->inputs.axis.y == 0 ||
    inf->event.key.code == inf->inputs.keys.back) {
        inf->pressed = 0;
    }
}

void update_keys(wininf *inf, player *p)
{
    if (inf->c_scene == QUIZ) handle_quiz(inf);
    if (inf->waiting_key == 1 && inf->event.type == sfEvtKeyPressed) {
        inf->waiting_key = 37; inf->tmp_key = inf->event.key.code;
    }
    if (inf->waiting_key == 38 && inf->event.type == sfEvtKeyReleased) {
        inf->waiting_key = 0;
        inf->options_menu->focus = 1;
    }
}

void update_events(wininf *inf, player *p)
{
    while (sfRenderWindow_pollEvent(inf->win, &inf->event)) {
        update_inputs(inf);
        update_keys(inf, p);
        if (inf->event.type == sfEvtClosed)
            sfRenderWindow_close(inf->win);
        if (inf->event.type == sfEvtKeyPressed && inf->event.key.code ==
        sfKeyRShift)
            sfRenderWindow_close(inf->win);
        if (inf->event.type == sfEvtKeyPressed && inf->event.key.code ==
        inf->inputs.keys.back && inf->interacting != 0)
            inf->interacting = 0;
    }
    inf->time.cursor += inf->time.dt;
    update_pause(inf, p); update_pause2(inf, p);
    draw_intros(inf, p);
}

void draw_intros(wininf *inf, player *p)
{
    float update = 0.0f;
    int value = inf->event.type == sfEvtKeyPressed;
    if (inf->c_scene == MAIN_MENU)
        update = (!sfJoystick_isConnected(0) || value) ? 0.35f : 0.45f;
    else {
        update = (inf->c_menu == NONE ? 0.0f : (!sfJoystick_isConnected(0) ||
        inf->event.type == sfEvtKeyPressed) ? 0.35f : 0.45f);
    }
    if (inf->c_scene == INTRO) manage_intro(inf);
    if (inf->time.cursor > update) {
        inf->time.cursor = 0.0f;
        if (inf->current_menu && (inf->inputs.axis.x == 0 ||
            inf->inputs.axis.y == 0))
            inf->current_menu->press = 0;
        check_back(inf, p);
    }
}
