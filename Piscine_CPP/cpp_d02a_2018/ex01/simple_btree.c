/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include "simple_btree.h"

bool_t btree_is_empty(tree_t tree)
{
    if (tree == NULL)
        return (TRUE);
    return (FALSE);
}

unsigned int btree_get_size(tree_t tree)
{
    unsigned int i;

    if (tree == NULL)
        return (0);
    i = 1 + btree_get_size(tree->right) + btree_get_size(tree->left);
    return (i);
}

unsigned int btree_get_depth(tree_t tree)
{
    unsigned int left_branch;
    unsigned int right_branch;

    if (tree == NULL)
        return (0);
    left_branch = btree_get_depth(tree->left);
    right_branch = btree_get_depth(tree->right);
    if (left_branch > right_branch)
        return (left_branch + 1);
    return (right_branch + 1);
}

bool_t btree_create_node(tree_t *node_ptr, double value)
{
    *node_ptr = malloc(sizeof(node_t));
    if (*node_ptr == NULL)
        return (FALSE);
    (*node_ptr)->value = value;
    return (TRUE);
}

bool_t btree_delete(tree_t *root_ptr)
{
    if (*root_ptr == NULL)
        return (FALSE);
    *root_ptr = NULL;
    return (TRUE);
}