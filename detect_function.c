/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** detect_function
*/

#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <ctype.h>

int command_ls(char **argv, char **env)
{
    int status = 0;
    char *path = searh_env("PATH", env);
    pid_t pid;
    char **paths;

    if (path == NULL) {
        my_putstr("ls: Command not found.\n");
        return 1;
    }
    pid = fork();
    paths = my_str_to_word_array_2(path);
    if (pid == 0) {
        for (int i = 0; paths[i] != NULL; i++) {
            paths[i] = my_strcat(paths[i], "/ls");
            execve(paths[i], argv, env);
        }
        return 84;
    } else
        waitpid(pid, &status, 0);
    return 0;
}

int command_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return 0;
}

int command_exit(char **argv)
{
    if (my_strcmp(argv[0], "exit") == 0)
        return 84;
    return 0;
}

static int condi(int i, char **env, char **argv)
{
    char *var_new;

    if (my_strncmp(env[i], argv[1], my_strlen(argv[1])) == 0 &&
        env[i][my_strlen(argv[1])] == '=') {
        var_new = malloc(my_strlen(argv[1]) + my_strlen(argv[2]) + 2);
        my_strcpy(var_new, argv[1]);
        my_strcat(var_new, "=");
        my_strcat(var_new, argv[2]);
        env[i] = var_new;
        return 0;
    }
    return 1;
}

static int is_alnum_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (((str[i]) >= '0' && (str[i]) <= '9') ||
            ((str[i]) >= 'A' && (str[i]) <= 'Z') ||
            ((str[i]) >= 'a' && (str[i]) <= 'z') ||
            (str[i]) == '_') {
        } else
            return 1;
    }
    return 0;
}

static int alnum_name(char **argv)
{
    if ((argv[1][0]) >= 'A' && (argv[1][0]) <= 'Z')
        return 0;
    if ((argv[1][0]) >= 'a' && (argv[1][0]) <= 'z')
        return 0;
    return 1;
}

int error_gestion_add(char **argv)
{
    if (argv[1] != NULL && (alnum_name(argv) == 1)) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (argv[1] != NULL && (is_alnum_str(argv[1]) == 1)) {
        my_printf("setenv: Variable name must"
            " contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

static int error_gestion(char **argv, char **env)
{
    if (error_gestion_add(argv) == 1)
        return 1;
    if (argv[2] != NULL && (is_alnum_str(argv[2]) == 1)) {
        my_printf("setenv: Variable "
            "value must contain alphanumeric characters.\n");
        return 1;
    }
    if (argv[3] != NULL && argv[2] != NULL && argv[1] != NULL) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (argv[1] == NULL) {
        command_env(env);
        return 1;
    }
    return 0;
}

int command_setenv(char **argv, char **env)
{
    char *var_new;
    int i;

    if (error_gestion(argv, env) == 1)
        return 1;
    if (argv[2] == NULL)
        argv[2] = "";
    for (i = 0; env[i] != NULL; i++) {
        if (condi(i, env, argv) == 0)
            return 0;
    }
    var_new = malloc(my_strlen(argv[1]) + my_strlen(argv[2]) + 2);
    my_strcpy(var_new, argv[1]);
    my_strcat(var_new, "=");
    my_strcat(var_new, argv[2]);
    env[i] = var_new;
    env[i + 1] = NULL;
    return 0;
}
