/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brtree_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:11:30 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 15:31:02 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>
void print(brtree *node);


int			cmp(int n_ten, brtree **node, char *num)
{
	char *str_node;

	str_node = (*node)->num; 
	if ((*node)->n_ten != n_ten)
		return (n_ten - (*node)->n_ten);
	else
	{
		while (*num)
		{
			if (*num != *str_node)
				return ((int)(*num - *str_node));
			num++;
			str_node++;
		}
		return (0);
	}
}

brtree		*create_leaf(brtree *parent)
{
	brtree *leaf;

	if ((leaf = malloc(sizeof(brtree))) == 0)
		return (0);
	leaf->left = 0;
	leaf->right = 0;
	leaf->parent = parent;
	leaf->num = 0;
	leaf->n_ten = -1;
	leaf->color = '0';
	leaf->leaf = '1';
	leaf->root = '0';
	return (leaf);
}

void		insert_node_in_leaf(brtree ***node, char *num,
		int n_ten, char *name_num)
{
	(**node)->left = create_leaf(**node);
	(**node)->right = create_leaf(**node);
	(**node)->num = num;
	(**node)->n_ten = n_ten;
	(**node)->name_num = name_num;
	(**node)->leaf = '0';
	(**node)->color = '1';
}

brtree		*create_root(char *num, int n_ten, char *name_num)
{
	brtree *node;
	
	if ((node = malloc(sizeof(brtree))) == 0)
			return (0);
	node->left = create_leaf(node);
	node->right = create_leaf(node);
	node->name_num = name_num;
	node->num = num;
	node->n_ten = n_ten;
	node->parent = 0;
	node->color = '0';
	node->leaf = '0';
	node->root = '1';
	return (node);
}

brtree		*brtree_insert_data(brtree **node, int n_ten, char *num, char *name_num, brtree **root)
{
	brtree *res;

	if (*node == 0)
	{
		*node = create_root(num, n_ten, name_num);
		return (*node);
	}
	if ((*node)->leaf == '1')
	{
		insert_node_in_leaf(&node, num, n_ten, name_num);
		balancing(*node, *root);
		return (*node);
	}
	else	if (cmp(n_ten, &(*node), num) < 0)
	{
		res = brtree_insert_data(&((*node)->left), n_ten, num, name_num, root);
		balancing(*node, *root);
		return (res);
	}
	else
	{
		res = brtree_insert_data(&((*node)->right), n_ten, num, name_num, root);
		balancing(*node, *root);
		return (res);
	}
}
