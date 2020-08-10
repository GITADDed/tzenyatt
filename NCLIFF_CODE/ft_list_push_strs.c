/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 06:02:12 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 18:51:53 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

char			*key(char *str)
{
	char		*key;
	int			i;
	int			k;

	i = 0;
	while (str[i] != ' ')
		i++;
	key = malloc(sizeof(char) * (i + 1));
	k = 0;
	while (k < i)
	{
		key[k] = str[k];
		k++;
	}
	key[k] = '\0';
	return (key);
}

char		*value(char *str)
{
	char		*value;
	int			i;

	while (*str != ':')
		str++;
	str++;
	i = 0;
	while (str[i])
		i++;
	value = malloc(sizeof(char) * (i + 1));
	i = 0;
	str++;
	while (str[i] != '\0')
	{
		value[i] = str[i];
		i++;
	}
	if (str[i - 1] == ' ')
		i--;
	value[i] = '\0';
	return (value);
}

t_list			*ft_list_push_strs(char **strs)
{
	t_list		*node;
	t_list		*head;
	int			i;

	i = 1;
	head = ft_create_elem(value(strs[0]), key(strs[0]));
	node = head;
	while (strs[i] != 0)
	{
		node->next = ft_create_elem(value(strs[i]), key(strs[i]));
		node = node->next;
		i++;
	}
	return (head);
}
