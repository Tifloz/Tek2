/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include <memory.h>
#include "bitmap.h"

int is_bigendian(void)
{
    int i = 7;
    char *pc = (char *)(&i);
    if (pc[0] == '\x7')
        return (0);
    else
        return (1);
}

void make_bmp_header(bmp_header_t *header, size_t size)
{
    memset(header, 0, sizeof(bmp_header_t));
    header->size = (uint32_t)(size * size * sizeof(uint32_t) +
        sizeof(bmp_header_t) + sizeof(bmp_info_header_t));
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
    header->magic = 0x4D42;
    if (is_bigendian())
        header->magic = 0x424D;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    memset(header, 0, sizeof(bmp_info_header_t));
    header->size = 40;
    header->width = (int32_t)size;
    header->height = (int32_t)size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = (uint32_t)(size * size * sizeof(uint32_t));
    header->v_resolution = 0;
    header->h_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}