/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** execute.c
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

static void condi_loopi(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        if (WCOREDUMP(status)) {
            my_printf("Segmentation fault (core dumped)\n");
        } else
            my_printf("Segmentation fault\n");
    }
}

static void loopiloop(int pid)
{
    int status;

    do {
        waitpid(pid, &status, WUNTRACED);
        if (WIFSIGNALED(status)) {
            condi_loopi(status);
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

static char *conditi(char *cmd, char **env)
{
    struct stat st;
    char *path = searh_env("PATH", env);
    char **dirs = my_str_to_word_array_2(path);
    char *abs_path = NULL;

    for (int i = 0; dirs[i]; i++) {
        abs_path = malloc(my_strlen(dirs[i]) + my_strlen(cmd) + 2);
        my_strcpy(abs_path, dirs[i]);
        my_strcat(abs_path, "/");
        my_strcat(abs_path, cmd);
        if (stat(abs_path, &st) == 0 && st.st_mode & S_IXUSR)
            return abs_path;
        free(abs_path);
    }
    return NULL;
}

static int is_dir(char *path)
{
    struct stat sb;

    stat(path, &sb);
    if (S_ISDIR(sb.st_mode))
        return 1;
    return 0;
}

int condi_fifou(char **argv, char **env)
{
    struct stat st;

    if (stat(argv[0], &st) == 0 && (st.st_mode & S_IXUSR)) {
        if (execve(argv[0], argv, env) == -1) {
            my_printf("%s: Exec format error. Wrong Architecture.\n", argv[0]);
            return 1;
        }
    } else {
        my_printf("%s: Command not found.\n", argv[0]);
        return 1;
    }
    return 0;
}

static int condi_fi(char **argv, char **env)
{
    char *abs_path;
    struct stat st;

    if (stat(argv[0], &st) == 0) {
        if (is_dir(argv[0]) == 1 && execve(argv[0], argv, env) == -1) {
            my_printf("%s: Permission denied.\n", argv[0]);
            return 1;
        }
        if (condi_fifou(argv, env) == 1)
            return 1;
    } else {
        abs_path = conditi(argv[0], env);
        if (abs_path == NULL || execve(abs_path, argv, env) == -1) {
            my_printf("%s: Command not found.\n", argv[0]);
            return 1;
        }
    }
    return 0;
}

int execute_file(char **argv, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        if (condi_fi(argv, env) == 1)
            return 1;
    } else
        loopiloop(pid);
    return 0;
}
