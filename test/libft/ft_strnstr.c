/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:22:06 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/28 13:22:10 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			my_string_compare(char *str1, char *str2)
{
	int i;

	i = 0;
	while (*str2 != '\0')
	{
		if (*str1 != *str2 || *str1 == '\0')
			return (i);
		++i;
		++str1;
		++str2;
	}
	return (-1);
}

char				*ft_strnstr(char *src, char *sough, int n_ch)
{
	int i;
	int j;

	i = 0;
	while (*(src + i) != '\0' && i < n_ch)
	{
		if ((j = my_string_compare(src + i, sough)) == -1)
		{
			if (i + j < n_ch)
				return (src + i);
			else
				return (0);
		}
		++i;
		++src;
	}
	return (0);
}
