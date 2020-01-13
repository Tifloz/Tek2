/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include "simple_btree.h"

double btree_get_max_value(tree_t tree)
{
    double left_branch = 0;
    double right_branch = 0;
    double max = 0;
    double root = 0;

    if (tree == NULL)
        return (0.0);
    root = tree->value;
    left_branch = btree_get_max_value(tree->left);
    right_branch = btree_get_max_value(tree->right);
    if (left_branch > right_branch)
        max = left_branch;
    else
        max = right_branch;
    if (max < root)
        max = root;
    return (max);
}

double btree_get_min_value(tree_t tree)
{
    double left_branch;
    double right_branch;

    if (tree == NULL)
        return (0.0);
    right_branch = btree_get_min_value(tree->right);
    left_branch = btree_get_min_value(tree->left);
    if (tree->left && tree->right) {
        double tmp = 0;
        return ((right_branch < (left_branch) ? tmp = right_branch :
            (tmp = left_branch)) < tree->value ? (tmp) : tree->value);
    }
    if (tree->left)
        return ((left_branch < tree->value ? left_branch : tree->value));
    if (tree->right)
        return ((right_branch < tree->value ? right_branch : tree->value));
    return (tree->value);
}