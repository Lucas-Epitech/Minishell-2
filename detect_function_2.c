/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** detect_function_2.c
*/

#include "include/my.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

static int condi_cd(int i, char **env, char **argv)
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

int command_setenv_cd(char **argv, char **env)
{
    char *var_new;
    int i;

    if (argv[2] == NULL)
        argv[2] = "";
    for (i = 0; env[i] != NULL; i++) {
        if (condi_cd(i, env, argv) == 0)
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

void condi_cont(char **envi)
{
    char *args[4];
    char cwd[1024];
    char *oldpwd_value = getcwd(cwd, sizeof(cwd));

    if (oldpwd_value != NULL) {
        args[0] = "setenv";
        args[1] = "OLDPWD";
        args[2] = oldpwd_value;
        args[3] = NULL;
        command_setenv_cd(args, envi);
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        args[0] = "setenv";
        args[1] = "OLDPWD";
        args[2] = cwd;
        args[3] = NULL;
        command_setenv_cd(args, envi);
    }
}

static int citonc(char **argv, char **envi)
{
    char *old_pwd = searh_env("OLDPWD", envi);

    condi_cont(envi);
    if (my_strcmp(argv[1], "-") == 0) {
        if (old_pwd != NULL) {
            chdir(old_pwd);
        } else
            my_printf("OLDPWD not set\n");
        return 1;
    }
    return 0;
}

int command_cd(char **argv, char **env)
{
    char **envi = env;
    struct stat sb2;

    if (argv[1] != NULL && argv[2] != NULL) {
        my_printf("cd: Too many arguments.\n");
        return 1;
    }
    if (argv[1] == NULL || (my_strcmp(argv[1], "~") == 0)) {
        chdir(searh_env("HOME", envi));
        return 1;
    }
    if (citonc(argv, envi) == 1)
        return 1;
    if (stat(argv[1], &sb2) == 0 && S_ISDIR(sb2.st_mode)) {
        chdir(argv[1]);
    } else if (stat(argv[1], &sb2) != 0) {
        my_printf("bash: cd: %s: No such file or directory.\n", argv[1]);
    } else
        my_printf("%s: Not a directory.\n", argv[1]);
    return 0;
}

static int condic(char **argv, char **env, int i)
{
    int j;

    if (my_strncmp(env[i], argv[1], my_strlen(argv[1])) == 0) {
        for (j = i; env[j] != NULL; j++) {
            env[j] = env[j + 1];
        }
        return 1;
    }
    return 0;
}

int command_unsetenv(char **argv, char **env)
{
    int i;

    if (argv[1] == NULL) {
        my_printf("Usage: unsetenv NAME\n");
        return 1;
    }
    for (i = 0; env[i] != NULL; i++) {
        if (condic(argv, env, i) == 1)
            return 1;
    }
    return 0;
}
