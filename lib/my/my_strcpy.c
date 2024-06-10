/*
** EPITECH PROJECT, 2023
** Essentiel
** File description:
** 4
*/

char *my_strcpy(char *dest, char const *src)
{
    int x;

    for (x = 0; src[x] != '\0'; x++) {
        dest[x] = src[x];
    }
    dest[x] = '\0';
    return dest;
}
