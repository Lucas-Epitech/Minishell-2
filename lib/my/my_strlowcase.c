/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 08
*/

char *my_strlowcase(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] >= 'A' && str[x] < 'Z') {
            str[x] = (str[x] + 32);
        }
        x = x + 1;
    }
    return str;
}
