/*
** EPITECH PROJECT, 2028
** my_printf
** File description:
** yanis and lucas
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

static void my_first_cases(const char *format, int i, va_list list)
{
    switch (format[i]) {
        case '%':
            my_putchar('%');
            break;
        case 'c':
            my_putchar((char) va_arg(list, int));
            break;
        case 'd':
        case 'i':
            my_putnbr(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
    }
}

static void my_second_cases(const char *format, int i, va_list list)
{
    int value = va_arg(list, unsigned int);

    switch (format[i]) {
        case 'x':
            if (value == 0) {
                my_putchar('0');
            } else {
                my_putnbr_base(value, "0123456789abcdef");
            }
            break;
        case 'X':
            if (value == 0) {
                my_putchar('0');
            } else {
                my_putnbr_base(value, "0123456789ABCDEF");
            }
            break;
    }
}

static void my_third_cases(const char *format, int i, va_list list)
{
    char *hex = "0123456789abcdef";

    switch (format[i]) {
        case 'p':
            my_putstr("0x");
            my_putlongnbr_base(va_arg(list, long long int), hex);
            break;
        case 'o':
            my_putnbr_base(va_arg(list, unsigned), "01234567");
            break;
        case 'F':
        case 'f':
            my_putfloat(va_arg(list, double), 6);
            break;
    }
}

static void my_fourth_cases(const char *format, int i, va_list list)
{
    switch (format[i]) {
        case 'u':
            my_putnbr_unsigned(va_arg(list, unsigned));
            break;
    }
}

static int is_flag(const char *format, int i)
{
    char *flags = "aeuiopsdfgxcn";

    for (int n = 0; n < my_strlen(flags); n++) {
        if (format[i] != flags[i] || format[i] != '#') {
            return (1);
        }
    }
    return (0);
}

static void which_case(const char *format, int i, va_list list)
{
    if (is_flag(format, i) == 0) {
        my_putstr("%");
        return;
    }
    if (format[i] == '%' || format[i] == 'c' || format[i] == 'd') {
        my_first_cases(format, i, list);
    } else if (format[i] == 'i' || format[i] == 's') {
        my_first_cases(format, i, list);
    }
    if (format[i] == 'x' || format[i] == 'X') {
        my_second_cases(format, i, list);
    }
    if (format[i] == 'o' || format[i] == 'p') {
        my_third_cases(format, i, list);
    } else if (format[i] == 'f' || format[i] == 'F') {
        my_third_cases(format, i, list);
    }
    if (format[i] == 'u') {
        my_fourth_cases(format, i, list);
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            which_case(format, i, list);
            count++;
        } else {
            my_putchar(format[i]);
            count++;
        }
        va_end(list);
    }
    return count;
}
