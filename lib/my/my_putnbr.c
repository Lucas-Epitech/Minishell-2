/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** put nbr
*/

#include "../../include/my.h"

int my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}
