/*
** EPITECH PROJECT, 2023
** Essentiel
** File description:
** 3
*/

#include "../../include/my.h"
#include <limits.h>

int my_nchar_isnum(char const *str, int n)
{
    if (str[n] >= '0' && str[n] <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int int_is_neg(char const *str)
{
    int nb_sub = 0;

    for (int x = 0; my_nchar_isnum(str, x) == 0; x++) {
        if (str[x] == '-') {
            nb_sub++;
        }
    }
    return (nb_sub % 2);
}

int my_str_to_int(char const *str)
{
    int result = 0;
    int x = 0;

    if (str[0] == '-') {
        x++;
    }
    while (str[x] != '\0') {
        result = result * 10 + str[x] - '0';
        x++;
    }
    if (str[0] == '-') {
        result = result * -1;
    }
    if (result > INT_MAX || result < INT_MIN)
        result = 0;
    return result;
}

int my_getnbr(const char *str)
{
    int x = 0;
    int y = int_is_neg(str);
    char nb_str[x + y + 1];

    while (my_nchar_isnum(str, x) == 1) {
        x++;
    }
    x = 0;
    if (y == 1) {
        nb_str[x] = '-';
        x++;
    }
    while (my_nchar_isnum(str, x) == 1) {
        nb_str[x] = str[x];
        x++;
    }
    nb_str[x] = '\0';
    return my_str_to_int(nb_str);
}
