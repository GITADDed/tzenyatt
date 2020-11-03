/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:06:50 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/28 20:06:53 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int sign;
	int num;

	sign = -1;
	num = 0;
	while (*str == ' ' || *str == 9)
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str != '+' && *str != '-' && *str < 48 && *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 - (*str - 48);
		++str;
	}
	return (num * sign);
}
