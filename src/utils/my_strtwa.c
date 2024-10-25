/*
** EPITECH PROJECT, 2022
** my_strtwa
** File description:
** Function to reproduce fekjlfzejp but output is double array
*/

#include "rpg.h"
#include <stdlib.h>

int is_valid_char(char c, const char *limiter)
{
    for (int i = 0; limiter[i] != '\0'; i++) {
        if (c == limiter[i]) return 0;
    }
    return 1;
}

int count_str_split(char const *str, char const *limiter)
{
    int word_len = 0;
    int space = 1;
    int str_in_str = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 39 || str[i] == 34) str_in_str = !str_in_str;
        if (is_valid_char(str[i], limiter) && space) {
            word_len++;
            space = 0;
        }
        if (!is_valid_char(str[i], limiter) && !space && !str_in_str) {
            space++;
        }
    }
    return word_len;
}

int my_word_length(char const *str, int x, char const *limiter)
{
    int length = 0;
    int q = 0;
    for ( ; str[x] != '\0' && (is_valid_char(str[x], limiter) || q); x++, length++) {
        if (str[x] == 39 || str[x] == 34) q = 1;
    }
    return q ? length - 2 : length;
}

int my_count_non_alpha(int x, char const *str, char const *limiter)
{
    int	length = 0;
    for ( ; !is_valid_char(str[x], limiter); x++, length++);
    return length;
}

char **my_strtwa(char const *str, char const *limiter)
{
    int word_array_length = count_str_split(str, limiter);
    int last_word = my_count_non_alpha(0, str, limiter);
    char **my_array = malloc(sizeof(char*) * (word_array_length + 1));
    for (int i = 0; i < word_array_length; i++) {
        int word_len = my_word_length(str, last_word, limiter);
        my_array[i] = malloc(sizeof(char) * (word_len + 1));
        for (int local = 0; local < word_len; local++) {
            int cond = (str[last_word] == 39 || str[last_word] == 34) ? 1 : 0;
            my_array[i][local] = str[last_word + local + cond];
        }
        my_array[i][word_len] = '\0';
        char c = my_array[i][word_len - 1];
        my_array[i][word_len - 1] = c == '\n' ? '\0' : c;
        last_word += word_len;
        last_word += my_count_non_alpha(last_word, str, limiter);
    }
    my_array[word_array_length] = 0;
    return my_array;
}