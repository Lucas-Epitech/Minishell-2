/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 13
*/

int my_str_islower(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] < 'a' || str[x] > 'z') {
            return 0;
        }
        x++;
    }
    return 1;
}
