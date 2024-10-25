/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** getline
*/

#if defined(_MSC_VER)
    #include <stdio.h>
    #include <stdlib.h>

    #include <stdio.h>
#include <stdlib.h>

    size_t getline(char **lineptr, size_t *n, FILE *stream) {
        if (lineptr == NULL || stream == NULL) {
            return -1;
        }

        if (*lineptr == NULL || *n == 0) {
            *n = 128;
            *lineptr = malloc(*n);
            if (*lineptr == NULL) {
                return -1;
            }
        }

        size_t total_read = 0;
        int c;

        while ((c = fgetc(stream)) != EOF) {
            if (total_read + 1 >= *n) {
                size_t new_size = *n * 2;
                char *new_lineptr = realloc(*lineptr, new_size);
                if (new_lineptr == NULL) {
                    return -1;
                }
                *lineptr = new_lineptr;
                *n = new_size;
            }

            (*lineptr)[total_read++] = (char)c;

            if (c == '\n' || c == '\r') {
                break;
            }
        }

        if (total_read == 0 && c == EOF) {
            return -1;
        }

        (*lineptr)[total_read] = '\0';
        
        return total_read;
    }
#endif