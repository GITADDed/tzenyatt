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

static size_t		lnch(char const *s, char c, size_t *len_words, size_t *par)
{
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	(*len_words) = 0;
	while (*s)
	{
		if (*s != c)
			(*len_words)++;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			len++;
		++s;
	}
	(*len_words) += len;
	*par = 0;
	if (len == 0)
		len++;
	return (len);
}

static void			*ft_free(char ***ptr)
{
	free(*ptr);
	return (0);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**ptr;
	size_t		len;

	j = 0;
	if (s == 0 || (ptr = malloc((lnch(s, c, &len, &i) + 1) * 8)) == 0)
		return (0);
	if ((*ptr = (char *)ft_calloc((len + 1), sizeof(char))) == 0)
		return (ft_free(&ptr));
	while (*s)
	{
		if (*s != c)
			*(*ptr + i++) = *s;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			*(*ptr + i++) = '\0';
			*(ptr + ++j) = (*ptr + i);
		}
		s++;
	}
	if (j == 0)
		j++;
	*(ptr + j) = 0;
	return (ptr);
}
