/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** Task02
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);
    int x;

    for (x = 0; src[x] != '\0' && x < nb; x++) {
        dest[len_dest + x] = src[x];
    }
    dest[len_dest + x] = '\0';
    return dest;
}
