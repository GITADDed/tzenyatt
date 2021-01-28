#include "ft_printf.h"

int flag_parcer(t_printf *structure, char **format)
{
    int res;

    res = 1;
    while (**format == '-' || **format == '0')
    {
        if (**format == '-')
            structure->minus = '-';
        else
            structure->zero = '0';
        (*format)++;
    }
    if (**format)
        res = 0;
    return (res);
}

int width_parcer(t_printf *structure, char **format, va_list argptr)
{
    int res;

    res = 1;
    while (**format >= '0' && **format <= '9')
    {
        if (structure->width == -1)
            structure->width = 0;
        structure->width = structure->width * 10 + (**format - '0');
        (*format)++;
    }
    if (**format == '*' && structure->width == -1)
    {
        structure->width = va_arg(argptr, int);
        (*format)++;
        if (structure->width < 0)
        {
            structure->minus = '-';
            structure->zero = -1;
            structure->width *= -1;
        }
    }
    if (**format == '\0')
        res = 0;
    return (res);
}

int parce_precision(t_printf *structure, char **format, va_list argptr)
{
    int res;

    res = 1;
    if (**format == '.')
    {
        (*format)++;
        structure->precision = 0;
        while (**format >= '0' && **format <= 9)
        {
            structure->precision = structure->precision * 10 + (**format + '0');
            (*format)++;
        }
        if (**format == '*')
        {
            structure->precision = va_arg(argptr, int);
            (*format)++;
            if (structure->precision < 0)
                structure->precision = -1;
        }
        if (**format)
            res = 0;
    }
    return (res);
}

t_printf    *init_struct(void)
{
    t_printf *structure;

    structure = (t_printf*)malloc(sizeof(t_printf));
    if (structure != 0)
    {
        structure->precision = -1;
        structure->type = -1;
        structure->minus = -1;
        structure->width = -1;
        structure->zero = -1;
    }
    return (structure);
}

t_printf    *fill_in_struct(char **format, va_list argptr)
{
    t_printf *structure;
    int can_i_parce_next;

    can_i_parce_next = 1;
    structure = init_struct();
    if (structure != 0)
    {
        if (flag_parcer(structure, format) == 0 || width_parcer(structure, format, argptr) == 0 || parce_precision(structure, format, argptr) == 0)
            can_i_parce_next = 0;
        if (ft_strchr("cspdiuxX%", **format))
            structure->type = *((*format)++);
        else
            can_i_parce_next = 0;
    }
    if (can_i_parce_next == 0)
    {
        free(structure);
        structure = 0;
    }
    return (structure);
}