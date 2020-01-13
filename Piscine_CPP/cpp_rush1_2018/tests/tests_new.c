/*
** EPITECH PROJECT, 2022
** cpp_rush1_2018
** File description:
** Created by Florian Louvet,
*/
#include <string.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include "../object.h"
#include "../player.h"
#include "../new.h"
#include "../point.h"
#include "../vertex.h"
#include "../char.h"
#include "../int.h"
#include "../float.h"

Test(new, object_have_good_class)
{
    Object *player = new(Player);

    cr_assert_str_eq(((Class *)player)->__name__, "Player");
    delete(player);
}

Test(new, object_is_correctly_deleted)
{
    Object *player = new(Player);

    delete(player);
    cr_assert_eq(((Class *)player)->__str__, NULL);
}

Test(point, example)
{
    Object *point = new(Point, 42, -42);
    cr_assert_str_eq(str(point), "<Point (42, -42)>");
    delete(point);
}

Test(point, null_test)
{
    Object *point = new(Point, NULL, NULL);
    cr_assert_str_eq(str(point), "<Point (0, 0)>");
    delete(point);
}

Test(point, positive_values)
{
    Object *point = new(Point, 3, 43);
    cr_assert_str_eq(str(point), "<Point (3, 43)>");
    delete(point);
}

Test(point, negative_values)
{
    Object *point = new(Point, -20, -42);
    cr_assert_str_eq(str(point), "<Point (-20, -42)>");
    delete(point);
}

Test(point, point_add)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    cr_assert_str_eq(str(addition(p1, p2)), "<Point (14, 15)>");
    delete(p1);
    delete(p2);
}

Test(point, point_sub)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    cr_assert_str_eq(str(subtraction(p1, p2)), "<Point (10, 11)>");
    delete(p1);
    delete(p2);
}

Test(point, point_mult)
{
    Object *p1 = new(Point, 1, 2);
    Object *p2 = new(Point, 4, 5);
    cr_assert_str_eq(str(multiplication(p1, p2)), "<Point (4, 10)>");
    delete(p1);
    delete(p2);
}

Test(point, point_div)
{
    Object *p1 = new(Point, 1, 2);
    Object *p2 = new(Point, 4, 5);
    cr_assert_str_eq(str(division(p1, p2)), "<Point (0, 0)>");
    delete(p1);
    delete(p2);
}

Test(point, point_operators)
{
    Object *p1 = new(Point, 1, 2);
    Object *p2 = new(Point, 4, 5);
    int res = 0;

    if (gt(p2, p1))
        res++;
    if (lt(p1, p2))
        res++;
    if (!eq(p1, p2))
        res++;

    cr_assert_eq(res, 3);
    delete(p1);
    delete(p2);
}

Test(vertex, example)
{
    Object *vertex = new(Vertex, 0, 1, 2);
    cr_assert_str_eq(str(vertex), "<Vertex (0, 1, 2)>");
    delete(vertex);
}

Test(vertex, null_test)
{
    Object *vertex = new(Vertex, NULL, NULL, NULL);
    cr_assert_str_eq(str(vertex), "<Vertex (0, 0, 0)>");
    delete(vertex);
}

Test(vertex, positive_values)
{
    Object *vertex = new(Vertex, 3, 43, 4);
    cr_assert_str_eq(str(vertex), "<Vertex (3, 43, 4)>");
    delete(vertex);
}

Test(vertex, negative_values)
{
    Object *vertex = new(Vertex, -20, -42, -68);
    cr_assert_str_eq(str(vertex), "<Vertex (-20, -42, -68)>");
    delete(vertex);
}

Test(vertex, vertex_add)
{
    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);
    cr_assert_str_eq(str(addition(v1, v2)), "<Vertex (5, 7, 9)>");
    delete(v1);
    delete(v2);
}

Test(vertex, vertex_sub)
{
    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);
    cr_assert_str_eq(str(subtraction(v1, v2)), "<Vertex (-3, -3, -3)>");
    delete(v1);
    delete(v2);
}

Test(vertex, vertex_mult)
{
    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);
    cr_assert_str_eq(str(multiplication(v1, v2)), "<Vertex (4, 10, 18)>");
    delete(v1);
    delete(v2);
}

Test(vertex, vertex_div)
{
    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);
    cr_assert_str_eq(str(division(v1, v2)), "<Vertex (0, 0, 0)>");
    delete(v1);
    delete(v2);
}

Test(vertex, vertex_overators)
{
    Object *v1 = new(Vertex, 1, 2, 0);
    Object *v2 = new(Vertex, 4, 5, 1);
    int res = 0;

    if (gt(v2, v1))
        res++;
    if (lt(v1, v2))
        res++;
    if (!eq(v1, v2))
        res++;

    cr_assert_eq(res, 3);
    delete(v1);
    delete(v2);
}

Test(character, char_test)
{
    Object *character = new(Char, 'a');
    cr_assert_str_eq(str(character), "<Char (a)>");
    delete(character);
}

Test(character, character_add)
{
    Object *v1 = new(Char, 'A');
    Object *v2 = new(Char, '\n');
    cr_assert_str_eq(str(addition(v1, v2)), "<Char (K)>");
    delete(v1);
    delete(v2);
}

Test(character, character_sub)
{
    Object *v1 = new(Char, 'K');
    Object *v2 = new(Char, '\n');
    cr_assert_str_eq(str(subtraction(v1, v2)), "<Char (A)>");
    delete(v1);
    delete(v2);
}

Test(character, character_mult)
{
    Object *v1 = new(Char, '\n');
    Object *v2 = new(Char, '\n');
    cr_assert_str_eq(str(multiplication(v1, v2)), "<Char (d)>");
    delete(v1);
    delete(v2);
}

Test(character, character_div)
{
    Object *v1 = new(Char, 'd');
    Object *v2 = new(Char, '\n');
    cr_assert_str_eq(str(division(v1, v2)), "<Char (\n)>");
    delete(v1);
    delete(v2);
}

Test(character, character_overators)
{
    Object *v1 = new(Char, 'a');
    Object *v2 = new(Char, 'b');
    int res = 0;

    if (gt(v2, v1))
        res++;
    if (lt(v1, v2))
        res++;
    if (!eq(v1, v2))
        res++;

    cr_assert_eq(res, 3);
    delete(v1);
    delete(v2);
}

Test(float_nb, float_test)
{
    Object *float_nb = new(Float, 2.03);
    cr_assert_str_eq(str(float_nb), "<Float (2.030000)>");
    delete(float_nb);
}

Test(float_nb, float_nb_add)
{
    Object *v1 = new(Float, 2.3);
    Object *v2 = new(Float, 2.4);
    cr_assert_str_eq(str(addition(v1, v2)), "<Float (4.700000)>");
    delete(v1);
    delete(v2);
}

Test(float_nb, float_nb_overators)
{
    Object *v1 = new(Float, 2.5);
    Object *v2 = new(Float, 4.6);
    float res = 0;

    if (gt(v2, v1))
        res++;
    if (lt(v1, v2))
        res++;
    if (!eq(v1, v2))
        res++;

    cr_assert_eq(res, 3);
    delete(v1);
    delete(v2);
}

Test(integer, int_test)
{
    Object *integer = new(Int, 2);
    cr_assert_str_eq(str(integer), "<Int (2)>");
    delete(integer);
}

Test(integer, integer_add)
{
    Object *v1 = new(Int, 2);
    Object *v2 = new(Int, 2);
    cr_assert_str_eq(str(addition(v1, v2)), "<Int (4)>");
    delete(v1);
    delete(v2);
}

Test(integer, integer_sub)
{
    Object *v1 = new(Int, 2);
    Object *v2 = new(Int, 1);
    cr_assert_str_eq(str(subtraction(v1, v2)), "<Int (1)>");
    delete(v1);
    delete(v2);
}

Test(integer, integer_mult)
{
    Object *v1 = new(Int, 2);
    Object *v2 = new(Int, 2);
    cr_assert_str_eq(str(multiplication(v1, v2)), "<Int (4)>");
    delete(v1);
    delete(v2);
}

Test(integer, integer_div)
{
    Object *v1 = new(Int, 2);
    Object *v2 = new(Int, 2);
    cr_assert_str_eq(str(division(v1, v2)), "<Int (1)>");
    delete(v1);
    delete(v2);
}

Test(integer, integer_overators)
{
    Object *v1 = new(Int, 1);
    Object *v2 = new(Int, 2);
    int res = 0;

    if (gt(v2, v1))
        res++;
    if (lt(v1, v2))
        res++;
    if (!eq(v1, v2))
        res++;

    cr_assert_eq(res, 3);
    delete(v1);
    delete(v2);
}