/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 13
*/

int my_str_isnum(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] < '0' || str[x] > '9') {
            return 0;
        }
        x++;
    }
    return 1;
}
