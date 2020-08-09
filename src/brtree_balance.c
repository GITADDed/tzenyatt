/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brtree_balance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:30:08 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 15:39:21 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void		rotate_left(brtree *node, brtree **root)
{
	brtree *y = node->right;

    /* establish x->right link */
    node->right = y->left;
    if (y->left->leaf != '1')
		y->left->parent = node;

    /* establish y->parent link */
    if (y->leaf != '1')
		y->parent = node->parent;
    if (node->parent)
	{
        if (node == node->parent->left)
            node->parent->left = y;
        else
            node->parent->right = y;
    } else {
        root = &y;
    }

    /* link x and y */
    y->left = node;
    if (node->leaf != '1')
		node->parent = y;
}

void		rotate_right(brtree *node, brtree **root)
{
    brtree *y = node->left;

    node->left = y->right;
    if (y->right->leaf != '1')
		y->right->parent = node;
    if (y->leaf != '1')
		y->parent = node->parent;
    if (node->parent)
	{
        if (node == node->parent->right)
            node->parent->right = y;
        else
            node->parent->left = y;
    } else {
        root = &y;
    }
    y->right = node;
    if (node->leaf != '1')
		node->parent = y;
}

void		balancing(brtree *node, brtree *root)
{
    /* check Red-Black properties */
    while (node->root != '1' && node->parent->color == '1') {
        /* we have a violation */
        if (node->parent == node->parent->parent->left) {
            brtree *y = node->parent->parent->right;
            if (y->color == '1') {

                /* uncle is RED */
                node->parent->color = '0';
                y->color = '0';
                node->parent->parent->color = '1';
                node = node->parent->parent;
            } else {

                /* uncle is BLACK */
                if (node == node->parent->right) {
                    /* make x a left child */
                    node = node->parent;
                    rotate_left(node, &root);
                }

                /* recolor and rotate */
                node->parent->color = '0';
                node->parent->parent->color = '1';
                rotate_right(node->parent->parent, &root);
            }
        } else {

            /* mirror image of above code */
            brtree *y = node->parent->parent->left;
            if (y->color == '1') {

                /* uncle is RED */
                node->parent->color = '0';
                y->color = '0';
                node->parent->parent->color = '1';
                node = node->parent->parent;
            } else {

                /* uncle is BLACK */
                if (node == node->parent->left) {
                    node = node->parent;
                    rotate_right(node, &root);
                }
                node->parent->color = '0';
                node->parent->parent->color = '1';
                rotate_left(node->parent->parent, &root);
            }
        }
    }
    root->color = '0';
}

void		btree_apply_prefix(brtree *root, void (*applyf)(brtree *))
{
	if (root == 0)
		return ;
	applyf(root);
	if (root->left != 0)
		btree_apply_prefix(root->left, applyf);
	if (root->right != 0)
		btree_apply_prefix(root->right, applyf);
}
