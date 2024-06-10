/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 04
*/

char *my_strstr(char *str, char const *to_find)
{
    int x = 0;

    while (*str != '\0') {
        while (str[x] == to_find[x] && to_find[x] != '\0') {
            x++;
        }
        if (to_find[x] == '\0') {
            return (str);
        }
        str++;
    }
    return (str);
}
