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

#include "get_next_line.h"
#include <stddef.h>

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t s;

	if (dest == 0 && src == 0)
		return (0);
	s = ft_strlen(src);
	if (destsize == 0)
		return (s);
	i = 0;
	while (i < destsize - 1 && *(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = '\0';
	return (s);
}

void 	clr(char *str)
{
	while (*str)
	{
		*str = '\0';
		str++;
	}
}

char	*subbuff_checker(char *subbuff, char **line)
{
	char *point_to_nl;

	point_to_nl = 0;
	if (subbuff)
		if ((point_to_nl = ft_strchr(subbuff, '\n')))
		{
			*point_to_nl = '\0';
			if ((*line = ft_strdup(subbuff)) == 0)
			{
				errno = ENOMEM;
				return (0);
			}
			ft_strlcpy(subbuff, ++point_to_nl, ft_strlen(subbuff));
		}
		else
		{
			*line = ft_strdup(subbuff);
			(*line == 0) ? errno = ENOMEM : clr(subbuff);
		}
	else
		*line = ft_calloc(1, sizeof(char));
	return (point_to_nl);
}

int		get_next_line(int fd, char **line)
{
	static char		*subbuff;
	char			buf[BUFFER_SIZE + 1];
	size_t			readed_byte;
	char			*p_to_nl;
	char			*p;

	if ((*line = ft_calloc(1, sizeof(char))) == 0)
		return (-1);
	p_to_nl = subbuff_checker(subbuff, line);
	while(!p_to_nl && (readed_byte = read(fd, buf, BUFFER_SIZE)))
	{
		if (errno == ENOMEM)
			return (-1);
		buf[readed_byte] = '\0';
		if ((p_to_nl = ft_strchr(buf, '\n')))
		{
			*p_to_nl = '\0';
			subbuff = ft_strdup(++p_to_nl);
		}
		p = *line;
		*line = ft_strjoin(*line, buf);
		free(p);
	}
	return ((readed_byte || ft_strlen(subbuff) || ft_strlen(*line)) ? 1 : 0);
}

#include <stdio.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
	char *line;
	int fd;
	int status;
	char *path = "/Users/tzenyatt/CLionProjects/test/gnl/file";
	if (argc > 1)
		path = argv[1];
	fd = open(path, O_RDONLY);
//	for (int i = 0; i < 62; ++i) {
//		status = get_next_line(fd, &line);
//		printf("%d) %s | status = %d\n",i + 1, line, status);
//	}
	while ((status = get_next_line(fd, &line)))
	{
		printf("status = %d, %s\n", status, line);
	}
	printf("status = %d\n", status);
}
