/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:28:06 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/11 13:28:09 by tzenyatt         ###   ########.fr
 * */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"
#include <stddef.h>

//int 	my_readV2(int fd, char **line, char **buf, char **subbuff)
//{
//	char *point1;
//	char *point2;
//	char *point3;
//
//	if (**subbuff != '\0')
//	{
//		point1 = *subbuff;
//		point2 = *subbuff;
//		while (*point1 != '\n' && *point1 != '\0')
//			point1++;
//		if (*point1 == '\n')
//			*line = my_strjoin(*line, *subbuff);
//		else
//			my_readV2(fd, line, buf, subbuff);
////		free(*line);
////		if ((*line = (char *) malloc((point1 - *subbuff + 1) * sizeof(char))) ==
////				0)
////			return (-1);
////
////		point3 = *line;
////		while (point2 != point1) {
////			*point3 = *point2;
////			point3++;
////			point2++;
////		}
////		*point3 = '\0';
//		if (*point1 == '\0')
//		{
//			point2 = *subbuff;
//			while (point2 != point1)
//			{
//				*point2 = '\0';
//				point2++;
//			}
//		}
//		else
//		{
//			point1++;
//			point2 = *subbuff;
//			while (*point1 != '\0')
//			{
//				*point2 = *point1;
//				point2++;
//				point1++;
//			}
//			while (point2 != point1)
//			{
//				*point2 = '\0';
//				point2++;
//			}
//		}
//		return (1);
//	}
//	if (read(fd, *buf, BUFFER_SIZE) == -1)
//		return (0);
//	point1 = *buf;
//	point2 = *buf;
//
//	while (*point1 != '\n' && *point1 != '\0')
//		point1++;
//
//	if ((*line = (char *)malloc((point1 - *buf + 1) * sizeof(char))) == 0)
//		return (-1);
//	point3 = *line;
//
//	while (point2 != point1)
//	{
//		*point3 = *point2;
//		point3++;
//		point2++;
//	}
//	*point3 = '\0';
//
//	point1++;
//	point3 = *subbuff;
//	while (*point1 != '\0')
//	{
//		*point3 = *point1;
//		point3++;
//		point1++;
//	}
//
//	return (1);
//}
//
//int		get_next_line(int fd, char **line)
//{
//	static char *subbuff;
//	char *buff;
//	size_t i;
//
//	//  Выделяем память под буффер, в который будем читать строку
//	if ((buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)) == 0)
//		return (-1);
//	i = 0;
//	// Выделяем память под буффер если он не создан, который хранит не
//	// вывденные строки из файла
//	// Далее иницииализируем эти буфферы
//	if (subbuff == 0)
//	{
//		if ((subbuff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
//			return (-1);
//		// После выделения памяти инициализируем эти буфферы
//		while (i < BUFFER_SIZE + 1) {
//			buff[i] = '\0';
//			subbuff[i] = '\0';
//			i++;
//		}
//	}
//	else
//	{
//		while (i < BUFFER_SIZE + 1)
//		{
//			buff[i] = '\0';
//			i++;
//		}
//	}
//	// Запуск функции, которая рекурсивно пишет в line строку
//	return (my_readV2(fd, line, &buff, &subbuff));
//}

//char	*check_subbuff(char *subbuf, char **line)
//{
//	if (subbuf)
//	{
//
//	}
//	else
//	{
//		*line =
//	}
//}

int		get_next_line(int fd, char **line)
{
	static char *subbuff;
	char buf[BUFFER_SIZE + 1];
	int readed_byte;
	char *p_to_nl;
	int flag;

	if (subbuff)
		*line = ft_strdup(subbuff);
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		if(*line == 0)
			return (-1);
		**line = '\0';
	}
	flag = 1;
	while(flag && (readed_byte = read(fd, buf, BUFFER_SIZE)))
	{
		buf[readed_byte] = '\0';
		if ((p_to_nl = ft_strchr(buf, '\n')))
		{
			*p_to_nl = '\0';
			flag = 0;
			p_to_nl++;
			subbuff = ft_strdup(p_to_nl);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

#include <stdio.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
	char *line;
	int fd;
	char *path = "/Users/tzenyatt/CLionProjects/test/gnl/file";
	if (argc > 1)
		path = argv[1];
	fd = open(path, O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
