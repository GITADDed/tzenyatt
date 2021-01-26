#include "ft_printf.h"

void start_parser(char const *format, va_list argptr)
{
    char const *s;
    char c;

    s = format;
    while (*s)
    {
        if (*s == '%' && *(s + 1) != 0)
        {
            if (s[1] == 'd' || s[1] == 'i')
                print_num(va_arg(argptr, int));
            else
                if (s[1] == 'u')
                    print_unum(va_arg(argptr, unsigned int));
                else
                    if (s[1] == 's')
                        print_string(va_arg(argptr, char *));
                    else
                        if (s[1] == 'c')
                        {
                            c = va_arg(argptr, int);
                            write(1, &c, 1);
                        }
                        else
                            if (s[1] == 'X' || s[1] == 'x')
                                print_sixteen_base_num(va_arg(argptr, unsigned int), s[1]);
                            else
                                if (s[1] == 'p')
                                    print_sixteen_base_num_memory(va_arg(argptr, unsigned long long int));
            s += 2;
        }
        if (*s != '\0')
            write(1, s++, 1);
    }
}