/*
** EPITECH PROJECT, 2023
** Day 05
** File description:
** Task 04
*/

#include <limits.h>

int my_compute_power_rec(int nb, int power)
{
    if (power < 0) {
        return 0;
    }
    if (power == 0) {
        return 1;
    }
    if (nb * nb < INT_MIN || nb * nb > INT_MAX) {
        return 0;
    }
    return nb * my_compute_power_rec(nb, power - 1);
}
