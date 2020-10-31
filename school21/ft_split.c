/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:36:37 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 17:36:39 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_how_many_chr(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			len++;
		++s;
	}
	return (len);
}

static size_t		ft_lenword(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		++len;
	return (len);
}

char 		*ft_word(char const *s, char c, size_t *i)
{
	size_t		j;
	char		*pointer;

	j = 0;
	pointer = malloc(ft_lenword(s + *i, c) + 1);
	if (pointer == 0)
		return (0);
	while (*(s + *i) != c && *(s + *i))
	{
		*(pointer + j) = *(s + *i);
		(*i)++;
		j++;
	}
	*(pointer + j) = '\0';
	return (pointer);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**pointer_on_strings;

	pointer_on_strings = (char **)malloc((ft_how_many_chr(s, c) + 1) * sizeof
			(char *));
	if (pointer_on_strings == 0)
		return (0);
	i = 0;
	j = 1;
	*pointer_on_strings = ft_word(s, c, &i);
	while (*(s + i))
	{
		if (*(s + i - 1) == c)
		{
			*(pointer_on_strings + j) = ft_word(s, c, &i);
			if (*(pointer_on_strings + j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	*(pointer_on_strings + j) = 0;
	return (pointer_on_strings);
}
