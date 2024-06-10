/*
** EPITECH PROJECT, 2023
** Essentiel
** File description:
** 5
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int x = 0;

    while (src[x] != '\0') {
        dest[len_dest + x] = src[x];
        x++;
    }
    dest[len_dest + x] = '\0';
    return dest;
}
