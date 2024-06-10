/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** minishell
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

char *searh_env(char *path, char **env)
{
    char *name;
    char *line;
    int count = 0;

    while (env[count] != NULL)
        count++;
    for (int i = 0; i != count; i++) {
        line = my_strdup(env[i]);
        name = strtok(line, "=");
        if (my_strcmp(name, path) == 0)
            return strtok(NULL, "=");
    }
    return NULL;
}

int basic_command_2(char **argv, char **env)
{
    if (my_strcmp(argv[0], "setenv") == 0) {
        command_setenv(argv, env);
        return 1;
    }
    if (my_strcmp(argv[0], "cd") == 0) {
        command_cd(argv, env);
        return 1;
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        command_unsetenv(argv, env);
        return 1;
    }
    return 0;
}

int basic_command(char **argv, char **env)
{
    if (my_strcmp(argv[0], "ls") == 0) {
        if (command_ls(argv, env) == 1)
            return 0;
        return 1;
    }
    if (my_strcmp(argv[0], "pwd") == 0) {
        my_putstr(getcwd(NULL, 0));
        my_putchar('\n');
        return 1;
    }
    if (my_strcmp(argv[0], "env") == 0) {
        command_env(env);
        return 1;
    }
    if (basic_command_2(argv, env) == 1)
        return 1;
    return 0;
}

static int command_main(char **argv, char **env)
{
    if (basic_command(argv, env) == 0) {
        if (execute_file(argv, env) == 1)
            return 1;
    }
    return 0;
}

int main_loop(char **argv, char **env)
{
    if (argv != NULL && argv[0] != NULL) {
        if (command_exit(argv) == 84)
            return 84;
        if (command_main(argv, env) == 1)
            return 84;
    }
    return 0;
}

static int in_stty(void)
{
    if (isatty(0) == 1) {
        my_putstr("$> ");
        return 0;
    } else
        return 1;
}

int main(int const argc, char **argv, char **env)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    (void)argc;
    while (1) {
        in_stty();
        read = getline(&input, &len, stdin);
        if (read == -1) {
            my_printf("exit\n");
            return 0;
        }
        input[read - 1] = '\0';
        argv = my_str_to_word_array(input);
        if (main_loop(argv, env) == 84)
            return 0;
    }
}
