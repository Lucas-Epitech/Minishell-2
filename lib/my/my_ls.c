/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "../../include/my.h"

struct Options {
    bool l;
    bool a;
    bool R;
};

static void initialiser_options(struct Options *options)
{
    options->l = false;
    options->a = false;
    options->R = false;
}

static void option_pre(const char *argument, struct Options *options)
{
    char lettre;

    for (int i = 0; argument[i] != '\0'; i++) {
        lettre = argument[i];
        switch (lettre) {
            case 'l':
                options->l = true;
                break;
            case 'a':
                options->a = true;
                break;
            case 'r':
                options->R = true;
                break;
        }
    }
}

static void tester_option(const char *argument, struct Options *options)
{
    int position_tiret = -1;

    for (int i = 0; argument[i] != '\0'; i++) {
        if (argument[i] == '-') {
            position_tiret = i;
            break;
        }
    }
    if (position_tiret != -1 && argument[position_tiret + 1] != '\0') {
        option_pre(argument + position_tiret + 1, options);
    }
}

void afficher_user(const struct stat *s)
{
    struct passwd *owner_info = getpwuid(s->st_uid);
    struct group *group_info = getgrgid(s->st_gid);

    if (owner_info != NULL) {
        my_printf(" %s", owner_info->pw_name);
    } else {
        perror("getpwuid");
    }
    if (group_info != NULL) {
        my_printf(" %s", group_info->gr_name);
    } else {
        perror("getgrgid");
    }
}

static void afficher_droits(const char *chemin, const struct stat *s)
{
    char date_string[18];
    char *raw_time = ctime(&s->st_mtime);

    my_printf((s->st_mode & S_IRUSR) ? "r" : "-");
    my_printf((s->st_mode & S_IWUSR) ? "w" : "-");
    my_printf((s->st_mode & S_IXUSR) ? "x" : "-");
    my_printf((s->st_mode & S_IRGRP) ? "r" : "-");
    my_printf((s->st_mode & S_IWGRP) ? "w" : "-");
    my_printf((s->st_mode & S_IXGRP) ? "x" : "-");
    my_printf((s->st_mode & S_IROTH) ? "r" : "-");
    my_printf((s->st_mode & S_IWOTH) ? "w" : "-");
    my_printf((s->st_mode & S_IXOTH) ? "x" : "");
    my_printf(" %d", (long long) s->st_nlink);
    afficher_user(s);
    my_strncpy(date_string, raw_time + 4, 12);
    date_string[12] = '\0';
    my_printf(" %d", (long long) s->st_size);
    my_printf(" %s %s\n", date_string, chemin);
}

static void droit(const char *directory, const char *nom,
    const struct Options *options)
{
    char chemin[PATH_MAX];
    struct stat s;

    my_strcpy(chemin, directory);
    my_strcat(chemin, "/");
    my_strcat(chemin, nom);
    lstat(chemin, &s);
    if (options->l) {
        afficher_droits(nom, &s);
    } else
        my_printf("%s\n", nom);
}

void condi_start(const char *directory, const struct Options *options,
    struct stat *fileStat)
{
    struct Options options_copy = *options;

    if (options_copy.l) {
        afficher_droits(directory, fileStat);
        return;
    }
    my_printf("%s\n", directory);
    return;
}

void list_files(const char *directory, const struct Options *options)
{
    struct dirent *entry;
    struct Options options_copy = *options;
    struct stat fileStat;
    DIR *dir = opendir(directory);

    if (stat(directory, &fileStat) == 0 && S_ISREG(fileStat.st_mode)) {
        condi_start(directory, options, &fileStat);
        return;
    }
    if (dir == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        tester_option(entry->d_name, &options_copy);
        if (options_copy.a || entry->d_name[0] != '.')
            droit(directory, entry->d_name, &options_copy);
    }
    closedir(dir);
}

void cont(int argc, char *argv[], struct Options *options)
{
    bool option_specified = false;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            tester_option(argv[i], options);
            option_specified = true;
        } else {
            list_files(argv[i], options);
        }
    }
    if (option_specified && argc == 2) {
        list_files(".", options);
    }
}

int my_ls(int argc, char *argv[])
{
    struct Options options;

    initialiser_options(&options);
    if (argc == 1) {
        list_files(".", &options);
    } else
        cont(argc, argv, &options);
    return 0;
}
