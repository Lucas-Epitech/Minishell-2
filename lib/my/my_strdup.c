/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len = my_strlen(str) + 1;
    char *dup = malloc(len);
    int i;

    for (i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[i] = '\0';
    return (dup);
}
