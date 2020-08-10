/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 05:55:37 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/10 13:17:47 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

void		ft_list_push_back(t_list **begin_list, t_list *add_node)
{
	t_list *node;

	if (*begin_list != 0)
	{
		node = *begin_list;
		while ((node->next) != 0)
			node = node->next;
		node->next = ft_create_elem(add_node->value, add_node->key);
	}
	else
		*begin_list = ft_create_elem(add_node->value, add_node->key);
}
