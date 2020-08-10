/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:30:29 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/10 13:46:22 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>


int	cmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != 0)
	{
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	return (*str1 - *str2);
}

void		put_char(void *node)
{
	t_list *noda;
	char *str;

	noda = node;
	str = noda->value;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, " ", 1);
}

char		*ten_value(long len_num)
{
	char *result;
	long i;

	i = 1;
	if (len_num % 3 != 0 && len_num > 2)
		len_num -= len_num % 3;
	result = malloc(sizeof(char) * (len_num + 2));
	result[0] = '1';
	result[len_num] = '\0';
	while (i <= len_num)
	{
		result[i] = '0';
		i++;
	}
	return (result);
}

char		*pars_str(char *str, int n_symb)
{
	char		*result;
	int			i;

	result = malloc(sizeof(char) * (n_symb + 1));
	i = 0;
	while (i < n_symb)
	{
		result[i] = *str;
		str++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

long int		max_lens(t_list *list)
{
	long int max;

	max = -1;
	while (list != 0)
	{
		if (max < list->n_ten)
			max = list->n_ten;
		list = list->next;
	}
	return (max);
}

void		add_2_num(long int len_num,
		t_list ***result_list, t_list **list, char *num)
{
	char buf[3];
	
	buf[2] = '\0';
	buf[1] = '0';
	if (len_num % 3 == 1)
	{
		ft_list_push_back(*result_list, ft_list_find(*list, pars_str(num, 1), cmp));
	}
	else	if (*num == '1')
		ft_list_push_back(*result_list, ft_list_find(*list, pars_str(num, 2), cmp));
	else
	{
		buf[0] = *num;
		ft_list_push_back(*result_list, ft_list_find(*list, buf, cmp));
		buf[0] = *(num + 1);
		buf[1] = '\0';
		ft_list_push_back(*result_list, ft_list_find(*list, buf, cmp));
	}
}

void		add_3_num(long int len_num, char *num, t_list **list,
		t_list **result_list)
{
	long int i;
	long int new_len;

	i = 0;
	new_len = len_num;
	while (i < new_len)
	{
		if (len_num % 3 != 0)
		{
			add_2_num(len_num, &result_list, list, num);
			len_num -= len_num % 3;
			num += len_num % 3 - 1;
			i += len_num % 3 - 1;
			continue ;
		}
		if (len_num % 3 == 0 && len_num != 0)
		{
			ft_list_push_back(result_list, ft_list_find(*list, pars_str(num, 1), cmp));
			ft_list_push_back(result_list, ft_list_find(*list, ten_value(2), cmp));
			len_num--;
		}
		num++;
		i++;
	}
}

int			converter(char **argv, char **example)
{
	long int		max_len;
	long int		len_num;
	t_list			*result_list = 0;
	t_list			*list;
   	char			*num;
	int				k;
	
	list = ft_list_push_strs(example);
	len_num = 0;
	max_len = max_lens(list);
	num = argv[1];
	while (*num)
	{
		len_num++;
		num++;
	}
	if (max_len < len_num)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
		num = argv[1];
		while (*num)
		{
			k = len_num % 3;
			if (len_num % 3 == 0 && len_num != 0)
				k = 3;
			add_3_num(k, pars_str(num, k), &list, &result_list);
			num += k;
			len_num -= k;
			if (len_num >= 1)
				ft_list_push_back(&result_list, ft_list_find(list, ten_value(len_num + 2), cmp));
		}
		ft_list_foreach(result_list, put_char);
		return (1);
}
