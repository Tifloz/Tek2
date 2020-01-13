/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** check_map.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "args.h"

int verify_char(char c)
{
    if (c == '_' || c == 'e' || c == 'c' || c == '\n')
        return (0);
    return (1);
}

void get_map_height(s_args *a)
{
    int height = 0;

    while (a->map[height] != '\n')
        height++;
    a->height = height;
}

int check_map(s_args *a)
{
    int width = 0;

    for (int i = 0; a->map[i]; i++) {
        if (a->map[i] == '\n')
            width++;
        if (verify_char(a->map[i]) == 1) {
            fprintf(stderr, "Bad map\n");
            exit(84);
        }
    }
    if (width == 0) {
        fprintf(stderr, "Bad map\n");
        exit(84);
    }
    a->width = width;
    get_map_height(a);
    return (0);
}

int get_map_size(char *filename)
{
    struct stat sb;
    int size = 0;

    stat(filename, &sb);
    if ((size = sb.st_size) <= 0) {
        fprintf(stderr, "Bad map file\n");
        exit(84);
    }
    return (size);
}

void check_map_file(char *filename, s_args *args)
{
    int fd = 0;
    char *file_content = NULL;
    int size = get_map_size(filename);

    if ((file_content = malloc(sizeof(char) * (size + 1))) == NULL) {
        perror("malloc");
        exit(84);
    }
    if ((fd = open(filename, O_RDONLY)) == -1) {
        perror("open");
        exit(84);
    }
    file_content[size] = '\0';
    read(fd, file_content, size);
    args->map = file_content;
}