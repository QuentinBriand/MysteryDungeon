/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_quiz
*/

#include "quiz.h"

quiz *create_quiz(wininf *inf)
{
    quiz *qcm = my_malloc(sizeof(quiz)); qcm->clicked = 0;
    qcm->destroy = 0; qcm->tendance = 0; qcm->nbquestions = 0;
    qcm->nature = my_malloc(sizeof(int) * 15);
    qcm->addptsnature = my_malloc(sizeof(int) * 15);
    qcm->cursor = c_ele(inf->atlases.atlas, rootPath"/csv/quiz_cursor.csv", 1);
    for (int i = 0; i < 15; i++) {
        qcm->nature[i] = i; qcm->addptsnature[i] = 0;
    }
    qcm->questions = inf->lang ? load_csv(rootPath"/csv/quiz_questions_fr.csv") :
    load_csv(rootPath"/csv/quiz_questions_en.csv");
    for (; qcm->questions[qcm->nbquestions] != NULL; qcm->nbquestions++);
    qcm->actualquestion = 1; qcm->aquestions = NULL;
    qcm->quizbox = generate_textbox((sfVector2i) {385, 50},
        inf->atlases.atlas);
    sfSprite_setPosition(qcm->quizbox, (sfVector2f) {200, 720});
    sfSprite_setScale(qcm->quizbox, (sfVector2f) {4, 4});
    qcm->questions_quiz = create_questions_quiz(inf, qcm->questions,
        qcm->nbquestions); qcm->aq_quiz = qcm->questions_quiz->next;
    return qcm;
}
