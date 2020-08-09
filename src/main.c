/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:15:02 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 15:21:28 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdio.h>

void	print(brtree *root)
{
	printf("Root1 :num = %s, n_ten = %d, name_num = %s, color = %c, leaf = %c, root = %c\n", root->num, root->n_ten, root->name_num, root->color, root->leaf, root->root);
}

int			main(int argc, char **argv)
{
	brtree *root = 0;
	brtree *added;
	char *str3 = "three";
	brtree *new_root;

	brtree_insert_data(&root, 1, argv[2], "four", &root);
	btree_apply_prefix(root, &print);
	printf("FOUR--------------------------\n");
	brtree_insert_data(&root, 1, argv[4], "one", &root);
	btree_apply_prefix(root, &print);
	printf("ONE--------------------------\n");
	brtree_insert_data(&root, 1, argv[1], str3, &root);
	btree_apply_prefix(root, &print);
	printf("THREE--------------------------\n");
	brtree_insert_data(&root, 1, argv[5], "five", &root);
	btree_apply_prefix(root, &print);
	printf("FIVE--------------------------\n");
	brtree_insert_data(&root, 1, argv[3], "two", &root);
	btree_apply_prefix(root, &print);
	/*insert_node_in_leaf(&(root->right), argv[2], 1, "four");
	insert_node_in_leaf(&(root->left), argv[3], 1, "two");
	insert_node_in_leaf(&(root->left->left), argv[4], 1, "one");
	root->left->left->ki*/
//	printf("For five :num = %s, n_ten = %d, name_num = %s, color = %c, leaf = %c, root = %c\n", root->right->left->num, root->right->left->n_ten, root->right->left->name_num, root->right->left->color, root->right->left->leaf, root->right->left->root);
//	rotate_right(root->right, &new_root);
//	printf("For five :num = %s, n_ten = %d, name_num = %s, color = %c, leaf = %c, root = %c\n", root->right->right->num, root->right->right->n_ten, root->right->right->name_num, root->right->right->color, root->right->right->leaf, root->right->right->root);
	
}
