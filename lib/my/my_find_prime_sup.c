/*
** EPITECH PROJECT, 2023
** Day 05
** File description:
** Task 07
*/

int my_find_prime_sup(int nb)
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
