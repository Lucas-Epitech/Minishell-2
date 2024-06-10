/*
** EPITECH PROJECT, 2023
** Day05-Task02
** File description:
** Task02-my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0) {
        return 1;
    }
    if (nb < 0 || nb > 12) {
        return 0;
    }
    return nb * my_compute_factorial_rec(nb - 1);
}
