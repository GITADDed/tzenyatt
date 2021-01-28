#include "ft_printf.h"

int     print_di(t_printf *structure, va_list argptr)
{
    long     num;
    char    sign;

    sign = -1;
    num = va_arg(argptr, int);
    if (num < 0)
    {
        sign = '-';
        num *= -1;
    }
    return (print_process_num(structure, num, 10, sign));
}

int     print_ux(t_printf *structure, va_list argptr)
{
    long num;

    num = va_arg(argptr, unsigned int);
    return (print_process_num(structure, num, structure->type == 'u' ? 10 : 16, -1));
}

int     print_p(t_printf *structure, va_list argptr)
{
    long long int num;

    num = va_arg(argptr, long long int);
    return (print_process_num(structure, num, 16, -1));
}

int     print_c(t_printf *structure, va_list argptr)
{
    int size;
    char ch;

    size = 0;
    if (structure->type == 'c')
        ch = va_arg(argptr, int);
    else
        ch = '%';
    if (structure->minus != '-')
        size += print_width_str(structure, 1);
    ft_putchar(ch);
    structure->zero = -1;
    if (structure->minus == '-')
        size += print_width_str(structure, 1);
    return (++size);
}

int     print_s(t_printf *structure, va_list argptr)
{
    int size;
    char *str;
    int len_str;

    size = 0;
    str = va_arg(argptr, char*);
    if (str == 0)
        size = -1;
    else
    {
        len_str = ft_strlen(str);
        if (structure->precision != -1 || structure->minus != -1)
            structure->zero = -1;
        structure->precision = structure->precision < 0 ? len_str : structure->precision;
        if (structure->precision > len_str)
            structure->precision = len_str;
        if (structure->minus != '-')
            size += print_width_str(structure, structure->precision);
        size += print_precision_str(structure, str);
        if (structure->minus == '-')
            size += print_width_str(structure, structure->precision);
    }
    return (size);
}
