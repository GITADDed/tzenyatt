/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:28:57 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/11 13:29:03 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000

#endif

# include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>

void		*ft_calloc(size_t count, size_t size);
char 		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);

#endif
