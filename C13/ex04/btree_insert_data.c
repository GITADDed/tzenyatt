#include "ft_btree.h"

void	add(t_btree *node, void *item,int (*cmpf)(void *, void *))
{
	
	if (cmpf(item, node->item) < 0 && node->left == 0)
	{
		node->left = btree_create_node(item);
		return ;
	}
	else
		add(node);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	node;	

	if (*root == 0)
	{
		*root = btree_create_node(item);
		return ;
	}	
	else
	{
		node = *root;
		if (cmpf(item, node->item) < 0)
		{
			
		}
	}
}
