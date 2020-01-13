/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#include  <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../menger.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(menger, example_1, .init = redirect_all_std)
{
    menger(3, 1, 0, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("001 001 001\n");
}

Test(menger, example_2, .init = redirect_all_std)
{
    menger(9, 1, 0, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("003 003 003\n");
}

Test(menger, example_3, .init = redirect_all_std)
{
    menger(9, 2, 0, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("003 003 003\n001 001 001\n001 001 004\n"
                            "001 001 007\n001 004 001\n001 004 004\n"
                            "001 004 007\n001 007 004\n001 007 007\n");
}
