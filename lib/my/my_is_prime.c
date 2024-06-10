/*
** EPITECH PROJECT, 2023
** Day 05
** File description:
** Task 06
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int x = 2; x < nb; x = x +1) {
        if (nb % x == 0) {
            return 0;
        }
    }
    return 1;
}
