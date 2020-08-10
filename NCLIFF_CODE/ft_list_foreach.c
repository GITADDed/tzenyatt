/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:04:03 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 18:45:30 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *node;

	if (begin_list != 0)
	{
		node = begin_list;
		while (node->next != 0)
		{
			f(node);
			node = node->next;
		}
		f(node);
	}
}
