/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n) {
        i++;
    }
    if (i == n) {
        return (0);
    } else {
        return (int)(s1[i] - s2[i]);
    }
}
