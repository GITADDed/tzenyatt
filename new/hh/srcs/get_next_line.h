/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 03:27:30 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/25 18:07:07 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

char		*ft_stdup(char *s1);
size_t		ft_stlen(const char *st);
char		*ft_stchr(const char *st, int ch);
char		*ft_stjoin(char *s1, char const *s2);
size_t		ft_stcpy(char *dest, char *src);
int			get_next_line(int fd, char **line);

#endif
