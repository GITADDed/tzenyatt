/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:39:02 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/01 20:39:04 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		++s;
	}
}
