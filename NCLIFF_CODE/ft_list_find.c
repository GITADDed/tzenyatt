/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:59:53 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 19:02:37 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *node;

	node = begin_list;
	while (node != 0)
	{
		if (cmp(node->key, data_ref) == 0)
			return (node);
		node = node->next;
	}
	return (0);
}
