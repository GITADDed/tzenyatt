/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:25:17 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/28 14:32:28 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (0);
}

int			print_type(t_printf *structure, va_list argptr)
{
	int			size;
	char		type;

	type = structure->type;
	size = 0;
	if (type == 'd' || type == 'i')
		size = print_di(structure, argptr);
	else if (type == 's')
		size = print_s(structure, argptr);
	else if (type == 'c' || type == '%')
		size = print_c(structure, argptr);
	else if (type == 'p')
		size = print_p(structure, argptr);
	else if (type == 'u' || type == 'X' || type == 'x')
		size = print_ux(structure, argptr);
	return (size);
}

int			start_func(char *format, va_list argptr, int *result)
{
	int				error;
	t_printf		*structure;

	while (*format != '\0' && *format != '%')
	{
		ft_putchar(*(format++));
		(*result)++;
	}
	if (*format == '%')
	{
		format++;
		structure = fill_in_struct(&format, argptr);
		error = ((structure == 0) ? -1 : print_type(structure, argptr));
		if (error == -1)
			*result = -1;
		else
		{
			*result += error;
			free(structure);
		}
	}
	if (*format == '\0' || *result == -1)
		return (*result);
	return (start_func(format, argptr, result));
}

int			ft_printf(const char *format, ...)
{
	int			size;
	va_list		argptr;

	g_size = 0;
	size = 0;
	va_start(argptr, format);
	start_func((char*)format, argptr, &size);
	va_end(argptr);
	if (size == -1)
		g_size = -1;
	return (g_size);
}
