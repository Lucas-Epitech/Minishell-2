/*
** EPITECH PROJECT, 2023
** Day05-Task01
** File description:
** Task01-my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb == 0) {
        return 1;
    }
    if (nb < 0 || nb > 12) {
        return 0;
    }
    while (nb > 0) {
        result = result * nb;
        nb--;
    }
    return result;
}
