/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 02:40:28 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 21:24:12 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_create_elem(void *value, void *key)
{
	char		*str;
	t_list		*list;
	long		i;

	if ((list = malloc(sizeof(t_list))) == 0)
		return (0);
	i = 0;
	list->key = key;
	str = key;
	while (*str)
	{
		str++;
		i++;
	}
	list->n_ten = i;
	list->value = value;
	list->next = 0;
	return (list);
}
