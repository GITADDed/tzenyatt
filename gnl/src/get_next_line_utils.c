/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:28:30 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/21 12:09:58 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (str == 0)
		return (len);
	while (*(str + len) != '\0' && *(str + len) != '\n')
		++len;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*pointer;
	size_t		i;

	if (s1 == 0 || s2 == 0)
		return (0);

	pointer = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof
			(char));
	if (pointer == 0)
		return (0);
	i = 0;
	write(1, "debug\n", 6);
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
	printf("STRJOIN\n");
	return (pointer);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		++str;
	}
	if (*(str) == ch)
		return ((char *)str);
	printf("STRCHR\n");
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char		*pointer;
	size_t		len_s1;

	len_s1 = ft_strlen(s1);
	pointer = (char *)ft_calloc(len_s1 + 1, sizeof(char));
	if (pointer == 0)
		return (0);
	len_s1 = 0;
	while (*(s1 + len_s1))
	{
		*(pointer + len_s1) = *(s1 + len_s1);
		++len_s1;
	}
	write(1, "debugDUP\n", 9);
	return (pointer);
}

void	ft_bzero(void *s, size_t n)
{
	char		*temp_s;
	size_t		i;

	if (n != 0)
	{
		i = 0;
		temp_s = (char *)s;
		while (i < n)
		{
			*temp_s = 0;
			++i;
			++temp_s;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*pointer;

	pointer = (char *)malloc(count * size);
	if (pointer == 0)
		return (0);
	ft_bzero(pointer, count * size);
	return ((void *)pointer);
}
