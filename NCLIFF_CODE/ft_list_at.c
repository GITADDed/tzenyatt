/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 06:40:10 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/06 17:29:44 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int		i;
	t_list				*node;
	int					flag;

	flag = 0;
	i = 0;
	node = begin_list;
	while (i < nbr)
	{
		if (node == 0)
		{
			flag = 1;
			break ;
		}
		node = node->next;
		i++;
	}
	if (flag == 0)
		return (node);
	else
		return (node = 0);
}
