/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** handle_quiz
*/

#include "rpg.h"
#include "quiz.h"
#include "sounds.h"

void handle_quiz(wininf *inf)
{
    if (inf->c_scene != QUIZ || !inf->quiz) return;
    if (inf->inputs.interact == 0 && inf->quiz->clicked == 1) {
        sfSound_play(inf->sounds->sounds_board[MENU_SELECT]);
        inf->quiz->clicked = 0;
    }
}
