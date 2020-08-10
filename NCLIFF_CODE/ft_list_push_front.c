/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 04:29:11 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 17:07:15 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *value, void *key)
{
	t_list *node;

	if (*begin_list != 0)
	{
		node = ft_create_elem(value, key);
		node->next = *begin_list;
		*begin_list = node;
	}
	else
	{
		node = ft_create_elem(value, key);
		*begin_list = node;
	}
}
