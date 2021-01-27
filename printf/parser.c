#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		++str;
	}
	if (*(str) == ch)
		return ((char *)str);
	return (0);
}

void start_parser(char const *format, va_list argptr)
{
    char const *s;
    char c;
    char *point_to_flag;

    s = format;
    while (*s)
    {
        if (*s == '%' && *(s + 1) != 0)
        {
            point_to_flag = (char *)s + 1;
            while (!ft_strchr("diuscpXx", *s))
                ++s;
            if (*s == 'd' || *s == 'i')
            {
                flag_parser(va_arg(argptr, int), point_to_flag);
            }
            else
                if (*s == 'u')
                    print_unum(va_arg(argptr, unsigned int));
                else
                    if (*s == 's')
                        print_string(va_arg(argptr, char *));
                    else
                        if (*s == 'c')
                        {
                            c = va_arg(argptr, int);
                            write(1, &c, 1);
                        }
                        else
                            if (*s == 'X' || *s == 'x')
                                print_sixteen_base_num(va_arg(argptr, unsigned int), *s);
                            else
                                if (*s == 'p')
                                    print_sixteen_base_num_memory(va_arg(argptr, unsigned long long int));
            s++;
        }
        if (*s != '\0')
            write(1, s++, 1);
    }
}