#include "ft_btree.h"

void		btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left != 0)
		btree_apply_suffix(root->left, applyf);
	if (root->right != 0)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
