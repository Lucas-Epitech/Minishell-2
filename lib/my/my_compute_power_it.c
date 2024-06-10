/*
** EPITECH PROJECT, 2023
** Day05-Task03
** File description:
** Task03-my_compute_power_it
*/

#include <limits.h>

int my_compute_power_it(int nb, int p)
{
    int result = 1;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    while (p > 0) {
        if (result * nb < INT_MIN || result * nb > INT_MAX) {
            return 0;
        }
        result = result * nb;
        p--;
    }
    return result;
}
