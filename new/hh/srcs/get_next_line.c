/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:03:06 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/05/01 12:17:01 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_subbuf(char **subbuffer, char *p_to_nl)
{
	if (p_to_nl)
		return (1);
	free(*subbuffer);
	*subbuffer = 0;
	return (0);
}

void	free_subbuf_with_dup(char **subbuffer, char **p_to_nl)
{
	char	*p;

	**p_to_nl = '\0';
	p = *subbuffer;
	*subbuffer = ft_stdup(++(*p_to_nl));
	free(p);
}

char	*subbuff_checker(char *subbuff, char **line)
{
	char	*point_to_nl;

	point_to_nl = 0;
	if (subbuff)
	{
		point_to_nl = ft_stchr(subbuff, '\n');
		if (point_to_nl)
		{
			*point_to_nl = '\0';
			*line = ft_stdup(subbuff);
			ft_stcpy(subbuff, ++point_to_nl);
		}
		else
			*line = ft_stdup(subbuff);
	}
	else
		*line = ft_stdup("");
	return (point_to_nl);
}

int	help_read(size_t *r_bytes, int fd, char buff[])
{
	int	res;

	*r_bytes = read(fd, buff, BUFFER_SIZE);
	res = *r_bytes;
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char				buf[BUFFER_SIZE + 1];
	size_t				read_bytes;
	char				*p_to_nl;
	static char			*subbuffer;
	char				*p;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	p_to_nl = subbuff_checker(subbuffer, line);
	while (!p_to_nl && help_read(&read_bytes, fd, buf))
	{
		if (line == 0)
			return (-1);
		buf[read_bytes] = '\0';
		p_to_nl = ft_stchr(buf, '\n');
		if (p_to_nl)
			free_subbuf_with_dup(&subbuffer, &p_to_nl);
		p = *line;
		*line = ft_stjoin(*line, buf);
		free(p);
	}
	return (free_subbuf(&subbuffer, p_to_nl));
}
