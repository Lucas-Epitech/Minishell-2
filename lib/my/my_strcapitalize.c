/*
** EPITECH PROJECT, 2023
** Day 06
** File description:
** Task 10
*/

void caps(char *str, int i)
{
    if (str[i] >= 97 && str[i] <= 122) {
        str[i] = (str[i] - 32);
    }
}

void low(char *str, int i)
{
    if (str[i] >= 65 && str[i] <= 90){
        str[i] = (str[i] + 32);
    } else {
        str[i] = str[i];
    }
}

void zero(char *str, int *i)
{
    if (*i == 0){
        caps(str, *i);
        *i = *i + 1;
    }
}

void if_parts(char *str, int i)
{
    int x = i - 1;

    if ((str[x] > 0 && str[x] < 48) || (str[x] > 57 && str[x] < 65)){
        caps(str, i);
    } else if ((str[x] > 122) || (str[x] > 90 && str[x] < 97)) {
        caps(str, i);
    } else {
        low(str, i);
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        zero(str, &i);
        if_parts(str, i);
        i = i + 1;
    }
    return str;
}
