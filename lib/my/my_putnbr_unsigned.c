/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** put nbr
*/

#include "../../include/my.h"

int my_putnbr_unsigned(unsigned int nb)
{
    if (nb > 9)
        my_putnbr_unsigned(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
