/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 21:18:42 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/07/26 23:21:03 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			how_much_chars(char *str)
{
	int result;

	result = 0;
	while (*(str + result) != '\0')
		result++;
	return (result);
}

char		*ft_strstr(char *str, char *to_find)
{
	char *pointer;

	if (*to_find == '\0')
		return (str);
	if (*str == '\0')
		return (0);
	while (*str != *to_find)
		str++;
	pointer = str;
	if (how_much_chars(to_find) > how_much_chars(str))
		return (0);
	while (*to_find)
	{
		if (*to_find != *str)
			return (0);
		to_find++;
		str++;
	}
	return (pointer);
}
