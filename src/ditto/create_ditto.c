/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** c_eles
*/

#include "intro.h"
#include "ditto.h"

ditto_a *create_ditto(wininf *inf)
{
    sfView_zoom(inf->camera.view, 1.0f * SIZE);
    sfView_setCenter(inf->camera.view, (sfVector2f){960.0f, 540.0f});
    sfRenderWindow_setView(inf->win, inf->camera.view);
    ditto_a *cditto = malloc(sizeof(ditto_a)); cditto->plan = DITTOINIT;
    for (int i = 0, j = 1; i < 4; i++, j++)
        cditto->ditto[i] = c_ele(inf->atlases.atlas, rootPath"/csv/ditto.csv", j);
    for (int i = 1; i < 4; i++) {
        sfColor ditto = sfSprite_getColor(cditto->ditto[i].sprite);
        sfSprite_setColor(cditto->ditto[i].sprite,
        sfColor_fromRGBA(ditto.r, ditto.g, ditto.b, ditto.a - 125));
    }
    cditto->conga = my_music_from_file(rootPath"/music/00_conga.ogg");
    sfMusic_setVolume(cditto->conga, inf->volumes[1]);
    sfMusic_setLoop(cditto->conga, sfTrue);
    cditto->color = my_hsvtorgb(rand() % 360, 29, 100); return cditto;
}
