/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTEST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:10:10 by ncliff            #+#    #+#             */
/*   Updated: 2020/08/10 13:23:02 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_for_arg.h"
#include "test_file.h"
#include "ft_list.h"
#include <stdio.h>

int			converter(char **argv, char **mas);

int main(int argc, char **argv)
{
	char *file;
	char *num;
	char **mass;

	mass = NULL;
	file = "numbers.dict.txt";
	num = NULL;
	if (cheak_arg(argc, argv, &file, &num))
	{
		if (cheak_file(file) != NULL)
		{
			mass = mass_f(cheak_file(file), 0, 0, 0);
		}
		else
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	converter(argv, mass);
	return (0);
}
