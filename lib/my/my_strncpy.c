/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int x = 0; x < n || src[x] == '\0'; x++) {
        dest[x] = src[x];
    }
    return dest;
}
