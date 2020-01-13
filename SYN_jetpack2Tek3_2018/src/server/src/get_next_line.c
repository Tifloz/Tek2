/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** return a line from a file without the '\n'
*/

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "commands.h"

#define READ_SIZE 10

void get_after_line(char **buffer)
{
    int pos = 0;
    int len = 0;
    char *tmp = *buffer;

    for (int i = 0; tmp && tmp[i] && tmp[i] != '\n'; i++)
        pos++;
    pos++;
    for (int i = 0; tmp && tmp[i + pos]; i++) {
        tmp[i] = tmp[i + pos];
        len++;
    }
    for (int i = len; tmp && tmp[i]; i++)
        tmp[i] = 0;
    *buffer = tmp;
}

void get_before_line(char **str)
{
    int pos = 0;
    char *tmp = *str;

    for (int i = 0; tmp && tmp[i] && tmp[i] != '\n'; i++)
        pos++;
    for (int i = pos; tmp && tmp[i]; i++)
        tmp[i] = 0;
    *str = tmp;
}

char *my_strcat(char *str, char *cat)
{
    int len = 0;
    int lencat = 0;
    char *concat = NULL;

    for (int i = 0; str && str[i]; i++)
        len++;
    for (int i = 0; cat && cat[i]; i++)
        lencat++;
    if (!(concat = malloc(sizeof(char) * (len + lencat + 1))))
        return (NULL);
    for (int i = 0; str && str[i]; i++)
        concat[i] = str[i];
    for (int i = 0; cat && cat[i]; i++)
        concat[len + i] = cat[i];
    concat[len + lencat] = 0;
    if (str)
        free(str);
    return (concat);
}

int get_line(int fd, char **str, char *buffer, int *reader)
{
    for (int i = 0; buffer && buffer[i]; i++) {
        if (buffer[i] == '\n') {
            *str = my_strcat(*str, buffer);
            return (0);
        }
    }
    *str = my_strcat(*str, buffer);
    *reader = read(fd, buffer, READ_SIZE);
    buffer[*reader] = 0;
    if (!buffer[0])
        return (0);
    return (get_line(fd, str, buffer, reader));
}

char *get_next_line(int fd)
{
    int reader = 1;
    static char *buffer = NULL;
    char *str = NULL;

    if (buffer == NULL) {
        buffer = malloc(sizeof(char) * (READ_SIZE + 1));
        if (buffer == NULL)
            return (NULL);
        for (int i = 0; i < READ_SIZE + 1; i++)
            buffer[i] = '\0';
    }
    get_line(fd, &str, buffer, &reader);
    get_before_line(&str);
    get_after_line(&buffer);
    if (reader == 0) {
        free(buffer);
        return (NULL);
    }
    return (str);
}