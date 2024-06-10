/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** Task20
*/

#include <stdio.h>

int my_showstr(char const *str)
{
    while (*str != '\0') {
        if ((*str >= 32 && *str <= 126) || *str == '\n' || *str == '\t') {
            putchar(*str);
        } else {
            printf("\\%02x", (unsigned char)*str);
        }
        str++;
    }
    return 0;
}
