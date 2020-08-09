/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:58:51 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 15:20:26 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* left = link on left child, the same way for right.
 * parent = link in previous node.
 * num = number in digit view.
 * n_ten = how many digit in num.
 * name_num = number in human languege view.
 * color (black = '0' or red = '1') ('' is mean that character in ascii)
 * it done for memory
 * leaf (YES = '1' NO = '0')
 * root (YES = '1' NO = '0')
 * 
 * Laws for red and black tree :
 * 1)Each node is colored in black or red.
 * 
 * 2)Leaves are declared NIL nodes (that is, "virtual" nodes, descendants
 * of nodes that are usually called leaves; they are "pointed"
 * to by NULL pointers). The leaves are painted black.
 * 
 * 3)If a node is red, then both of its children are black.
 * On all branches of a tree leading from its root to the leaves,
 * the number of black nodes is the same.*/

#ifndef BTREE_H
# define BTREE_H

typedef struct			s_brtree
{
	struct s_brtree		*parent;
	struct s_brtree		*left;
	struct s_brtree		*right;
	char				*num;
	int					n_ten;
	char				*name_num;
	char				color;
	char				leaf;
	char				root;
}						brtree;

brtree					*create_root(char *num, int n_ten, char *name_num);
brtree					*brtree_insert_data(brtree **node, int n_ten,
		char *num, char *name_num, brtree **root);
int						cmp(int n_ten, brtree **node, char *num);
brtree					*create_leaf(brtree *parent);
void					insert_node_in_leaf(brtree ***node, char *num,
		int n_ten, char *name_num);
void		rotate_left(brtree *node, brtree **root);
void		rotate_right(brtree *node, brtree **root);
void		balancing(brtree *node, brtree *root);
void		btree_apply_prefix(brtree *root, void (*applyf)(brtree *));

#endif
