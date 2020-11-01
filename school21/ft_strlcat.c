/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:34:20 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 22:34:24 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t len_dest_str;
	size_t len_src_str;

	len_dest_str = ft_strlen(dest);
	len_src_str = ft_strlen(src);
	i = 0;
	while (i < destsize - 1)
	{
		if (i >= len_dest_str)
			*(dest + i) = *(src + (i - len_dest_str));
		++i;
	}
	*(dest + i) = '\0';
	return (len_dest_str + len_src_str);
}
