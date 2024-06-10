/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** put nbr to base
*/

#include "../../include/my.h"

int my_putlongbase(long long int nbr, char const *base, int step)
{
    int a = 0;
    int len = my_strlen(base);
    int cpt = 0;

    while (nbr != 0) {
        a = nbr % len;
        nbr = nbr / len;
        cpt++;
        if (step == cpt) {
            my_putchar(base[a]);
            return 0;
        }
    }
    return 0;
}

int my_putlongnbr_base(long long int nbr, char const *base)
{
    long long int temp = nbr;
    int step = 0;
    int len = my_strlen(base);

    if (!base || len < 1)
        return 84;
    if (nbr < 0) {
        my_putchar('-');
        return my_putlongnbr_base(nbr * (-1), base);
    }
    while (temp != 0) {
        temp = temp / len;
        step++;
    }
    while (step > 0) {
        my_putlongbase(nbr, base, step);
        step--;
    }
    return 0;
}
