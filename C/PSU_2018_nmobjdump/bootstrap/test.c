/*
** EPITECH PROJECT, 2022
** PSU_2018_nmobjdump
** File description:
** Created by Florian Louvet,
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

#define MY_USAGE "USAGE: ./my_prog <lib.so>\n"
#define MY_ERROR "Error : There is a problem\n"

int main(int ac, char **av)
{
    void *handle;
    char *error;
    void (*cousine)();
    if (ac != 2)
        write(2, MY_USAGE, strlen(MY_USAGE));
    else {
        handle = dlopen(av[1], RTLD_LAZY);
        if (!handle) {
            write(2, MY_ERROR, strlen(MY_ERROR));
            exit(EXIT_FAILURE);
        }
        cousine = dlsym(handle, "about");
        error = dlerror();
        if (error) {
            write(2, error, strlen(error));
            exit(EXIT_FAILURE);
        }
        (*cousine)();
        dlclose(handle);
        exit(EXIT_SUCCESS);
    }
    return (0);
}
