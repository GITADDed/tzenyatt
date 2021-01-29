/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:53:51 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/28 14:55:54 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c)
{
	g_size += write(1, &c, 1);
}

int			n_length(long num, int base)
{
	int len;

	len = 0;
	while (num >= 0)
	{
		num /= base;
		len++;
		if (num == 0)
			break ;
	}
	return (len);
}

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void		print_base_num(long num, int base, char *base_alph)
{
	if (num == 0)
		return ;
	print_base_num(num / base, base, base_alph);
	ft_putchar(base_alph[num % base]);
}

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
