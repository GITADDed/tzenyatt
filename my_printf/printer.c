/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:42:57 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/28 14:47:05 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_di(t_printf *structure, va_list argptr)
{
	long	num;
	char	sign;

	sign = -1;
	num = va_arg(argptr, int);
	if (num < 0)
	{
		sign = '-';
		num *= -1;
	}
	return (print_process_num(structure, num, 10, sign));
}

int		print_ux(t_printf *structure, va_list argptr)
{
	long num;

	num = va_arg(argptr, unsigned int);
	return (print_process_num(structure, num,
				structure->type == 'u' ? 10 : 16, -1));
}

int		print_p(t_printf *structure, va_list argptr)
{
	long long int num;

	num = va_arg(argptr, long long int);
	return (print_process_num(structure, num, 16, -1));
}

int		print_c(t_printf *structure, va_list argptr)
{
	int			size;
	char		ch;

	size = 0;
	if (structure->type == 'c')
		ch = va_arg(argptr, int);
	else
		ch = '%';
	if (structure->minus != '-')
		size += print_width_str(structure, 1);
	ft_putchar(ch);
	structure->zero = -1;
	if (structure->minus == '-')
		size += print_width_str(structure, 1);
	return (++size);
}

int		print_s(t_printf *struc, va_list argptr)
{
	int			size;
	char		*str;
	int			len_str;
	char		*buf;

	size = 0;
	str = va_arg(argptr, char*);
	buf = str == 0 ? "(null)" : str;
	if (buf == 0)
		size = -1;
	else
	{
		len_str = ft_strlen(buf);
		if (struc->precision != -1 || struc->minus != -1)
			struc->zero = -1;
		struc->precision = struc->precision < 0 ? len_str : struc->precision;
		if (struc->precision > len_str)
			struc->precision = len_str;
		if (struc->minus != '-')
			size += print_width_str(struc, struc->precision);
		size += print_precision_str(struc, buf);
		if (struc->minus == '-')
			size += print_width_str(struc, struc->precision);
	}
	return (size);
}
