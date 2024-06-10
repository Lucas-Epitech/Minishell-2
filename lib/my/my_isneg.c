/*
** EPITECH PROJECT, 2023
** Task 03
** File description:
** ?
*/

#include <unistd.h>

int my_isneg(int nb)
{
    if (nb < 0)
        write(1, "N", 1);
    else
        write(1, "P", 1);
    return (0);
}
