/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** init_music
*/

#include "music.h"

void set_sound_musics(wininf *inf, int volume)
{
    for (int i = 0; i < COUNTMUSICS; i++)
        sfMusic_setVolume(inf->music->musics_board[i], volume);
}

s_music *init_musics(void)
{
    s_music *music = my_malloc(sizeof(s_music));
    char **csvmusics = load_csv(rootPath"/csv/music.csv");
    for (int i = 1, j = 0; csvmusics[i] != NULL && j < COUNTMUSICS; i++, j++) {
        char **actualmusic = my_strtwa(csvmusics[i], ";\n");
        music->musics_board[j] = my_music_from_file(actualmusic[0]);
        sfMusic_setLoop(music->musics_board[j], sfTrue);
        if (actualmusic[1] != NULL &&
        my_strcmp(actualmusic[1], "LORDDITTOMUSIC") == 0) {
            sfMusic_setMinDistance(music->musics_board[j], 25.0f);
            sfMusic_setPosition(music->musics_board[j],
            (sfVector3f) {232.0f, 0.0f, 105.0f});
        }
        if (actualmusic[1] != NULL &&
        my_strcmp(actualmusic[1], "LITTLEDITTOMUSIC") == 0) {
            sfMusic_setMinDistance(music->musics_board[j], 25.0f);
            sfMusic_setPosition(music->musics_board[j],
            (sfVector3f) {232.0f, 0.0f, 105.0f});
        } my_free_array(actualmusic);
    } return music;
}
