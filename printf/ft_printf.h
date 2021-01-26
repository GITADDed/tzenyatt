#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
void start_parser(char const *format, va_list argptr);
void print_num(int n);
void print_string(char *string);
void print_sixteen_base_num(unsigned int num, char size);
void print_unum(unsigned int n);
void print_sixteen_base_num_memory(unsigned long long int num);

#endif
