/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:33:34 by tzenyatt          #+#    #+#             */
/*   Updated: 2021/01/28 14:35:03 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_printf
{
	char		minus;
	char		zero;
	char		type;
	int			width;
	int			precision;
}				t_printf;

int				g_size;

int				ft_printf(const char *format, ...);
char			*ft_strchr(char *str, char ch);
int				print_type(t_printf *structure, va_list argptr);
int				start_func(char *format, va_list argptr, int *result);
int				flag_parcer(t_printf *structure, char **format);
int				width_parcer(t_printf *structure, char **format,
					va_list argptr);
int				parce_precision(t_printf *structure, char **format,
		va_list argptr);
t_printf		*init_struct(void);
t_printf		*fill_in_struct(char **format, va_list argptr);
int				print_di(t_printf *structure, va_list argptr);
int				print_ux(t_printf *structure, va_list argptr);
int				print_p(t_printf *structure, va_list argptr);
int				print_c(t_printf *structure, va_list argptr);
int				print_s(t_printf *structure, va_list argptr);
int				print_process_num(t_printf *structure, long long num, int base,
		char sign);
void			print_base_num(long num, int base, char *base_alph);
int				print_width(t_printf *structure, int len, char sign);
int				print_precision(t_printf *structure, int len, char sign);
int				print_width_str(t_printf *structure, int strlen);
int				print_precision_str(t_printf *structure, char *str);
void			ft_putchar(char c);
int				n_length(long num, int base);
void			ft_putstr(char *str);
int				ft_strlen(char *str);

#endif
