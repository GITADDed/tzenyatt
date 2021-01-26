#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    va_list argptr;

    va_start(argptr, format);

    start_parser(format, argptr);

    va_end(argptr);
    return (0);
}