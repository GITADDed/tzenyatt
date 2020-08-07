#include "ft_btree.h"

void	print(void *a)
{
	int *out;
	out = (int*)a;
	printf("%d\n", *out);
}

int main()
{
	t_btree *head;
	int a = 1;
	int b = 4;
	int c = 8;
	int k = 12;
	int *out;
	head = btree_create_node(&a);
	out = (int*) head->item;
	printf("%d\n", *out);
	head->left = btree_create_node(&b);
	head->right = btree_create_node(&c);
	head->left->left = btree_create_node(&k);
	btree_apply_prefix(head, &print);
	btree_apply_infix(head, &print);
	btree_apply_suffix(head, &print);
}
