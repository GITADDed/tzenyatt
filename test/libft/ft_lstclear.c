/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:18 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/02 13:52:20 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;

	node = *lst;
	while (node->next)
	{
		ft_lstdelone(node, del);
		node++;
	}
	lst = 0;
}
