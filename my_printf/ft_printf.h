#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_printf
{
    char minus;
    char zero;
    char type;
    int width;
    int precision;
} t_printf;

int ft_printf(const char *format, ...);
int start_func(char *format, va_list argptr, int *result);
void    ft_putchar(char c);
t_printf    *fill_in_struct(char **format, va_list argptr);
int print_type(t_printf *structure, va_list argptr);
int     n_length(long num, int base);
int print_process_num(t_printf *structure, long long num, int base, char sign);
int     print_di(t_printf *structure, va_list argptr);
int print_width(t_printf *structure, int len, char sign);
void    ft_putstr(char *str);
int print_precision(t_printf *structure, int len, char sign);
void    print_base_num(long num, int base, char *base_alph);
int     print_ux(t_printf *structure, va_list argptr);
int     print_p(t_printf *structure, va_list argptr);
int     print_c(t_printf *structure, va_list argptr);
int     print_s(t_printf *structure, va_list argptr);
int print_width_str(t_printf *structure, int strlen);
int print_precision_str(t_printf *structure, char *str);
int     ft_strlen(char *str);
char *ft_strchr(char *str, char ch);

#endif