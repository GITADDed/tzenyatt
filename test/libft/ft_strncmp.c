/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:50:15 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/28 19:50:17 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *str1, char *str2, int n_ch)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	int				i;

	i = 0;
	temp_s1 = (unsigned char *)str1;
	temp_s2 = (unsigned char *)str2;
	while (*temp_s1 != '\0' && *temp_s2 != '\0' && i < n_ch)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		++temp_s1;
		++i;
		++temp_s2;
	}
	return (*temp_s1 - *temp_s2);
}
