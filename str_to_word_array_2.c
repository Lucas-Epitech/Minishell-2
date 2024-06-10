/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_str_to_word_array.c
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int count_words_2(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            count++;
        }
    }
    count++;
    return count;
}

void copy_word_2(char *dest, const char *src)
{
    while (*src != ':' && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

const char *skip_word_2(const char *str)
{
    while (*str != ':' && *str != '\0')
        str++;
    return str;
}

char **my_str_to_word_array_2(const char *str)
{
    int i = 0;
    int num_words = count_words_2(str);
    char **array = malloc((num_words + 1) * sizeof(char *));

    if (array == NULL)
        return NULL;
    while (*str != '\0') {
        while (*str == ':')
            str++;
        if (*str != '\0') {
            array[i] = malloc((strlen(str) + 1) * sizeof(char));
            copy_word_2(array[i], str);
            str = skip_word_2(str);
            i++;
        }
    }
    array[i] = NULL;
    return array;
}

void free_word_array_2(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
