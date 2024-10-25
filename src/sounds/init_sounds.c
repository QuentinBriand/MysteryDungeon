/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** init_sounds
*/

#include "sounds.h"

void set_volume_musics(wininf *inf, int volume)
{
    for (int i = 0; i < COUNTSOUNDS; i++)
        sfSound_setVolume(inf->sounds->sounds_board[i], volume);
}

s_sounds *init_sounds(void)
{
    s_sounds *sounds = my_malloc(sizeof(s_sounds));
    char **csvsounds = load_csv(rootPath"/csv/sounds.csv");
    for (int i = 1, j = 0; csvsounds[i] != NULL && j < COUNTSOUNDS; i++, j++) {
        char **actualsound = my_strtwa(csvsounds[i], ";\n");
        sounds->sound_buffer[j] = my_buffer_from_file(actualsound[0]);
        sounds->sounds_board[j] = my_sound();
        sfSound_setBuffer(sounds->sounds_board[j], sounds->sound_buffer[j]);
        my_free_array(actualsound);
    }
    return sounds;
}
