/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_intro
*/

#include "intro.h"

void move_sun(intro_a *rpg)
{
    if (rpg->b_intro[2].rect.top == 481 && rpg->b_intro[2].rect.left >= 914) {
        rpg->b_intro[2].rect.top = 513;
        rpg->b_intro[2].rect.left = 720;
    }
    if (rpg->b_intro[2].rect.top == 513 && rpg->b_intro[2].rect.left >= 914) {
        rpg->b_intro[2].rect.top = 545;
        rpg->b_intro[2].rect.left = 914;
    }
    if (rpg->b_intro[2].rect.top == 545 && rpg->b_intro[2].rect.left >= 914) {
        rpg->b_intro[2].rect.top = 577;
        rpg->b_intro[2].rect.left = 720;
    }
    if (rpg->b_intro[2].rect.top == 577 && rpg->b_intro[2].rect.left >= 914) {
        rpg->b_intro[2].rect.top = 481;
        rpg->b_intro[2].rect.left = 720;
    }
}

void move_sun_reverse(intro_a *rpg)
{
    if (rpg->b_intro[3].rect.top == 483 && rpg->b_intro[3].rect.left >= 1205) {
        rpg->b_intro[3].rect.top = 515;
        rpg->b_intro[3].rect.left = 1011;
    }
    if (rpg->b_intro[3].rect.top == 515 && rpg->b_intro[3].rect.left >= 1205) {
        rpg->b_intro[3].rect.top = 547;
        rpg->b_intro[3].rect.left = 1011;
    }
    if (rpg->b_intro[3].rect.top == 547 && rpg->b_intro[3].rect.left >= 1205) {
        rpg->b_intro[3].rect.top = 579;
        rpg->b_intro[3].rect.left = 1011;
    }
    if (rpg->b_intro[3].rect.top == 579 && rpg->b_intro[3].rect.left >= 1205) {
        rpg->b_intro[3].rect.top = 483;
        rpg->b_intro[3].rect.left = 1011;
    }
}

intro_a *create_intro(wininf *inf)
{
    intro_a *intro = malloc(sizeof(intro_a));
    intro->plan = PLAN0; intro->valid = 0;
    for (int i = 0, j = 1; i < 4; i++, j++)
        intro->b_intro[i] = c_ele(inf->atlases.atlas, rootPath"/csv/intro.csv", j);
    for (int i = 1, j = 5; i < 4; i++, j++)
        intro->pkmintro[i] = c_ele(inf->atlases.atlas, rootPath"/csv/intro.csv", j);
    int rdmpkm = rand() % 20; rdmpkm = (rdmpkm == 0 ? 8 : rdmpkm + 8);
    intro->pkmintro[0] = c_ele(inf->atlases.atlas, rootPath"/csv/intro.csv", rdmpkm);
    sfColor base = sfSprite_getColor(intro->b_intro[3].sprite);
    sfSprite_setColor(intro->b_intro[3].sprite,
    (sfColor) {base.r, base.g, base.b, 0});
    intro->i_music1 =
    my_music_from_file(rootPath"/music/01_pkm_red_rescue_team_theme.ogg");
    intro->i_music2 = my_music_from_file(rootPath"/music/02_title_screen.ogg");
    return intro;
}
