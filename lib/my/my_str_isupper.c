/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 12
*/

int my_str_isupper(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] < 'A' || str[x] > 'Z') {
            return 0;
        }
        x++;
    }
    return 1;
}
