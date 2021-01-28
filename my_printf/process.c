#include "ft_printf.h"

int print_process_num(t_printf *structure, long long num, int base, char sign)
{
    int size;
    int num_len;

    size = 0;
    if (structure->precision != -1 || structure->minus != -1)
        structure->zero = -1;
    num_len = ((num == 0 && structure->precision == 0) ? 0 : n_length(num, base));
    if (structure->minus != '-')
        size += print_width(structure, num_len, sign);
    size += print_precision(structure, num_len, sign);
    if (num == 0 && structure->precision != 0)
        ft_putchar('0');
    if (structure->type == 'X')
        print_base_num(num, base, "0123456789ABCDEF");
    else
        print_base_num(num, base, "0123456789abcdef");
    if (structure->minus == '-')
        size += print_width(structure, num_len, sign);
    size += num_len;
    return (size);
}

int print_width(t_printf *structure, int len, char sign)
{
    int size;

    size = 0;
    if (sign != -1 && structure->zero != -1 && structure->precision == -1 && structure->minus == -1)
        ft_putchar(sign);
    if (structure->width > len && structure->width > structure->precision)
    {
        structure->width -= ((structure->precision > len) ? structure->precision : len);
        structure->width -= ((sign == -1) ? 0 : 1);
        structure->width -= ((structure->type == 'p') ? 2 : 0);
        while (size++ < structure->width)
            if (structure->zero == '0')
                ft_putchar('0');
            else
                ft_putchar(' ');
    }
    return ((size > structure ->width && size != 0) ? --size : size);
}

int print_precision(t_printf *structure, int len, char sign)
{
    int size;

    size = 0;
    if (sign != -1 && (structure->zero == -1 || structure->precision != -1 || structure->minus == '-'))
        ft_putchar('-');
    if (structure->type == 'p')
        ft_putstr("0x");
    if (structure->precision != -1 && structure->precision > len)
        while (size++ < structure->precision - len)
            ft_putchar('0');
    // size += ((sign == -1) ? 0 : 1);
    return (size += ((sign == -1) ? 0 : 1));
}

int print_width_str(t_printf *structure, int strlen)
{
    int size;
    char print_char;

    size = 0;
    print_char = ' ';
    structure->width -= strlen;
    if (structure->zero == '0')
        print_char = '0';
    while (size++ < structure->width)
        ft_putchar(print_char);
    return (size);
}

int print_precision_str(t_printf *structure, char *str)
{
    int size;

    size = 0;
    while (size++ < structure->precision && *str)
        ft_putchar(*(str++));
    return (size);
}
