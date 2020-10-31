/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:07:05 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 18:07:08 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*temp_dest;
	char		*temp_src;

	i = 0;
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (i < n)
	{
		if (*(temp_src + i) == c)
		{
			*(temp_dest + i) = c;
			return (dest);
		}
		*(temp_dest + i) = *(temp_src + i);
		++i;
	}
	return (dest);
}
