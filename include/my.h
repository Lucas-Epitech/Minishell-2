/*
** EPITECH PROJECT, 2023
** Base
** File description:
** my_h
*/

#pragma once
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_btree {
    char **command;
    struct s_btree *left;
    struct s_btree *right;
} btree_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_putnbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putnbr_base(int nbr, char const *base);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putfloat(double fl, int precision);
int my_putlongnbr_base(long long int nbr, char const *base);
int my_putnbr_unsigned(unsigned int nb);
int my_printf(const char *format, ...);
char *my_strdup(char *str);
char **my_str_to_word_array(const char *str);
int count_words(char const *str);
int command_ls(char **args, char **new_env);
int command_exit(char **argv);
int command_env(char **new_env);
int command_setenv(char **argv, char **new_env);
char *searh_env(char *path, char **new_env);
char **my_str_to_word_array_2(const char *str);
int command_cd(char **argv, char **new_env);
int command_unsetenv(char **argv, char **new_env);
int execute_file(char **argv, char **env);
int basic_command(char **argv, char **env);
void command_pipe(char **argv, char **env);
int find_command_av(char **argv, char **env);
void test_basic_command(void);
