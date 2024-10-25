/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_dream
*/

#include "dream.h"
#include "ditto.h"

dream_a *create_dream(wininf *inf)
{
    dream_a *dream = my_malloc(sizeof(dream_a));
    dream->plan = DREAMINIT;
    for (int i = 0, j = 1; i < 3; i++, j++) {
        dream->b_dream[i] = c_ele(inf->atlases.atlas, rootPath"/csv/dreams.csv", j);
    }
    dream->color = 0;
    sfColor changecolor = my_hsvtorgb(dream->color, 50, 100);
    for (int i = 0; i < 3; i++) {
        sfSprite_setColor(dream->b_dream[i].sprite, changecolor);
    }
    dream->music =
    my_music_from_file(rootPath"/music/04_welcome_to_the_world_of_pokemon.ogg");
    sfMusic_setLoop(dream->music, sfTrue);
    sfMusic_setVolume(dream->music, inf->volumes[1]);
    return dream;
}
