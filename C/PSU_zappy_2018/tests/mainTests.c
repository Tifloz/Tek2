/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by Florian Louvet,
*/
#include <netinet/in.h>
#include "../src/C/include/struct.h"
#include "../src/C/include/include.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void setup_struct(struct t_parse *parse)
{
    parse->port = 10;
    parse->freq = -10.0;
    parse->height = 2;
    parse->width = 2;
    parse->team_max = -1;
}

void redirect_all_stdout(void)
{
    cr_redirect_stderr();
}

Test(port, exit_code, .init=redirect_all_stdout, .exit_code = 84)
{
    struct t_parse parser;
    get_port("-10", &parser);
    cr_assert_stderr_eq_str("Error with the port");
}

Test(height, exit_code, .init=redirect_all_stdout, .exit_code = 84)
{
    struct t_parse parser;
    get_height("-2", &parser);
    cr_assert_stderr_eq_str("Error with the height", "");
}

Test(width, exit_code, .init=redirect_all_stdout, .exit_code = 84)
{
    struct t_parse parser;
    get_width("-2", &parser);
    cr_assert_stderr_eq_str("Error with the width", "");
}

Test(teamMax, exit_code, .init=redirect_all_stdout, .exit_code = 84)
{
    struct t_parse parser;
    get_teammax("-1", &parser);
    cr_assert_stderr_eq_str("Error with the number of members of each team",
        "");
}

Test(frequency, exit_code, .init=redirect_all_stdout, .exit_code = 84)
{
    struct t_parse parser;
    get_freq("-10", &parser);
    cr_assert_stderr_eq_str("Error with the frequency", "");
}

Test(port, good_usage, .init=redirect_all_stdout)
{
    struct t_parse parser;
    get_port("8080", &parser);
    cr_assert_stderr_neq_str("Error with the port");
}

Test(height, good_usage, .init=redirect_all_stdout)
{
    struct t_parse parser;
    get_height("10", &parser);
    cr_assert_stderr_neq_str("Error with the height", "");
}

Test(width, good_usage, .init=redirect_all_stdout)
{
    struct t_parse parser;
    get_width("10", &parser);
    cr_assert_stderr_neq_str("Error with the width", "");
}

Test(teamMax, good_usage, .init=redirect_all_stdout)
{
    struct t_parse parser;
    get_teammax("20", &parser);
    cr_assert_stderr_neq_str("Error with the number of members of each team",
        "");
}

Test(frequency, good_usage, .init=redirect_all_stdout)
{
    struct t_parse parser;
    get_freq("10", &parser);
    cr_assert_stderr_neq_str("Error with the frequency", "");
}