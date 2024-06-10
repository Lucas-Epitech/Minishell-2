/*
** EPITECH PROJECT, 2018
** my_putfloat.c
** File description:
** put float
*/

#include "../../include/my.h"

void my_putfloat(double f, int precision)
{
    int n;
    int digit;

    if (f < 0) {
        my_putchar('-');
        f = -f;
    }
    n = (int)f;
    my_putnbr(n);
    my_putchar('.');
    f -= n;
    for (int i = 0; i < precision; i++) {
        f *= 10;
        digit = (int)f;
        my_putnbr(digit);
        f -= digit;
    }
}
