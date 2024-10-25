/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** load_csv
*/

#include "atlas.h"
#include "rpg.h"

char **load_csv(char *filename)
{
    int lines = get_number_lines(filename);
    FILE *f = fopen(filename, "r");
    char **array = my_malloc((lines + 1) * sizeof(char *));
    char *line = NULL;
    size_t len = 0;
    for (int i = 0; i < lines; i++) {
        getline(&line, &len, f);
        array[i] = my_strdup(line, my_malloc);
    }
    array[lines] = 0;
    if (line) free(line);
    if (f) fclose(f);
    return array;
}

int get_number_lines(char *filename)
{
    FILE *f = fopen(filename, "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    for (; (read = getline(&line, &len, f)) != -1; count++);
    if (line) free(line);
    if (f) fclose(f);
    return count;
}
