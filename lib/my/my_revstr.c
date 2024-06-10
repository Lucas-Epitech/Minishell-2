/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 03
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int x = 0;
    int temp;

    while (x < len / 2) {
        temp = str[x];
        str[x] = str[(len - 1) - x];
        str[(len - 1) - x] = temp;
        x = x +1;
    }
    return str;
}
