/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** delete_quiz
*/

#include "rpg.h"
#include "quiz.h"

void delete_quiz(wininf *inf)
{
    my_free_array(inf->quiz->questions);
    free(inf->quiz);
    inf->quiz = NULL;
}
