/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task13
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] < 32 || str[x] >= 127) {
            return 0;
        }
        x++;
    }
    return 1;
}
