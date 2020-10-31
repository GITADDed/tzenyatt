/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:57:08 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 21:57:11 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t s;

	s = ft_strlen(src);
	i = 0;
	while (i < destsize - 1)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + destsize) = '\0';
	return (s);
}
