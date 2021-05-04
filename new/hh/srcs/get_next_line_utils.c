/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:28:30 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/24 03:38:44 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stlen(const char *st)
{
	size_t	len;

	len = 0;
	if (st == 0)
		return (len);
	while (*(st + len) != '\0')
		++len;
	return (len);
}

char	*ft_stjoin(char *s1, char const *s2)
{
	char		*pointer;
	size_t		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	pointer = (char *)malloc((ft_stlen(s1) + ft_stlen(s2) + 1)
			* sizeof(char));
	if (pointer == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		pointer[i] = *s1++;
		++i;
	}
	while (*s2)
	{
		pointer[i] = *s2++;
		++i;
	}
	*(pointer + i) = '\0';
	return (pointer);
}

char	*ft_stchr(const char *st, int ch)
{
	while (*st != '\0')
	{
		if (*st == ch)
			return ((char *)st);
		++st;
	}
	return (0);
}

char	*ft_stdup(char *s1)
{
	char		*pointer;
	size_t		len_s1;
	size_t		i;

	i = 0;
	len_s1 = ft_stlen(s1);
	pointer = (char *)malloc((len_s1 + 1) * sizeof(char));
	if (pointer == 0)
		return (0);
	while (i < len_s1)
	{
		pointer[i] = s1[i];
		++i;
	}
	pointer[len_s1] = '\0';
	return (pointer);
}

size_t	ft_stcpy(char *dest, char *src)
{
	size_t	i;
	size_t	s;

	if (dest == 0 && src == 0)
		return (0);
	s = ft_stlen(src);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = '\0';
	return (s);
}
