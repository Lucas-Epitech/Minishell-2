/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 06
*/

int my_str_isalpha(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if ((str[x] < 'A' || (str[x] > 'Z' && str[x] < 'a') || str[x] > 'z')) {
            return 0;
        }
        x++;
    }
    return 1;
}
