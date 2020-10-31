/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:45:25 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 16:45:29 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_chrcmp(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (-1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*pointer;

	pointer = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (pointer == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		if (ft_chrcmp(*s1, set) == 0)
		{
			*(pointer + i) = *s1;
			++i;
		}
		++s1;
	}
	*(pointer + i) = '\0';
	return (pointer);
}
