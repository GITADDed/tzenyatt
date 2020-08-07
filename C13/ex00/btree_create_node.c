#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree *node;

	if ((node = malloc(sizeof(t_btree))) == 0)
		return (0);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
