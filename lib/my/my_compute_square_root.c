/*
** EPITECH PROJECT, 2023
** Day 05
** File description:
** Task 05
*/

int my_compute_square_root(int nb)
{
    int x = 0;
    int result = 0;

    if (nb < 0) {
        return 0;
    }
    while (result < nb) {
        x++;
        result = x * x;
    }
    if (result == nb) {
        return x;
    }
    return 0;
}
