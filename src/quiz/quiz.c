/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** quiz
*/

#include "rpg.h"
#include "quiz.h"
#include "dream.h"

int chose_tendance(wininf *inf)
{
    int tendance = 0; int valtendance = inf->quiz->addptsnature[0];
    for (int i = 0; i < 13; i++) {
        if (valtendance < inf->quiz->addptsnature[i]) {
            tendance = i;
            valtendance = inf->quiz->addptsnature[i];
        }
    }
    return tendance;
}

void qcm(wininf *inf)
{
    if (inf->quiz->aq_quiz->next == NULL) {
        inf->quiz->destroy = 1; return;
    }
    if (inf->quiz->aquestions == NULL) {
        inf->quiz->aquestions =
        my_strtwa(inf->quiz->questions[inf->quiz->actualquestion], ";\n");
    }
    quiz_choice(inf);
    move_cursor_quiz(inf, &inf->quiz->cursor);
    sfRenderWindow_drawSprite(inf->win, inf->quiz->quizbox, NULL);
    sfRenderWindow_drawText(inf->win, inf->quiz->aq_quiz->question, NULL);
    sfRenderWindow_drawText(inf->win, inf->quiz->aq_quiz->answer1, NULL);
    sfRenderWindow_drawText(inf->win, inf->quiz->aq_quiz->answer2, NULL);
    if (inf->time.intro_anim < 0.4f)
            display_ele(inf->win, inf->quiz->cursor);
    else if (inf->time.intro_anim > 0.9f) inf->time.intro_anim = 0;
}

void draw_quiz(wininf *inf, player *p)
{
    if (inf->quiz == NULL) inf->quiz = create_quiz(inf);
    draw_dream(inf);
    qcm(inf);
    if (sfKeyboard_isKeyPressed(sfKeyRControl)) {
        sfMusic_stop(inf->dream->music);
        inf->c_scene = HOME;
    }
    if (inf->quiz->destroy == 1) {
        char **csv = load_csv(rootPath"/csv/quiz_choices.csv");
        inf->quiz->tendance = chose_tendance(inf);
        inf->settings->pokemon = chose_line(csv, inf->quiz->tendance,
        inf->quiz->addptsnature[13] ? 1 : 0);
        *p = *(init_player(*(inf), inf->settings->pokemon));
        inf->camera.target = p->test;
        inf->quiz->aq_quiz = inf->quiz->questions_quiz;
        sfMusic_stop(inf->dream->music);
        inf->c_scene = HOME;
    }
}
