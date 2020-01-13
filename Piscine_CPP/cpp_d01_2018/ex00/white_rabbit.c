/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** A function to find the white rabbit,
*/

#include <stdlib.h>
#include <stdio.h>

int follow_the_white_rabbit(void)
{
    int result = 0;
    while (1) {
        int val = (int)(random() % 37 + 1);
        result = result + val;
        if (val == 26 || val % 8 == 0)
            printf("backward\n");
        if (val == 15 || val == 10 || val == 23)
            printf("forward\n");
        if ((val >= 4 && val <= 6) || (val >= 17 && val <= 21) || val == 28)
            printf("left\n");
        if (val == 13 || (val >= 34 && val != 37))
            printf("right\n");
        if (result == 421 || val == 37 || val == 1) {
            printf("RABBIT!!!\n");
            break;
        }
    }
    return (result);
}
