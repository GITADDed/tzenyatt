#include "ft_printf.h"

int			ft_pr_type(t_printf *prc, va_list args, int *result)
{
	int buf;

	buf = 0;
	if (prc->typepf == 'd' || prc->typepf == 'i')
		buf = ft_proc_di(prc, args);
	else if (prc->typepf == 's')
		buf = ft_proc_s(prc, args);
	else if (prc->typepf == 'c' || prc->typepf == '%')
		buf = ft_proc_c(prc, args);
	else if (prc->typepf == 'u' || prc->typepf == 'x' || prc->typepf == 'X')
		buf = ft_proc_ux(prc, args);
	else if (prc->typepf == 'p')
		buf = ft_proc_p(prc, args);
	else if (prc->typepf == 'n')
		*result = 0;
	return (buf);
}

int			ft_pr_result(char *str, va_list args, int *result)
{
	int			err;
	t_printf	*prc;

	while (*str != '\0' && *str != '%')
	{
		ft_putchar(*(str++));
		++(*result);
	}
	if (*str == '%')
	{
		++str;
		prc = ft_get_spec(&(str), args);
		err = prc == NULL ? -1 : ft_pr_type(prc, args, result);
		if (err == -1)
			*result = -1;
		else
		{
			*result += err;
			free(prc);
		}
	}
	if (*str == '\0' || *result == -1)
		return (*result);
	return (ft_pr_result(str, args, result));
}

t_printf	*ft_init_spec(void)
{
	t_printf	*result;

	result = (t_printf*)malloc(sizeof(t_printf));
	if (result != NULL)
	{
		result->precisionpf = none;
		result->zeropf = none;
		result->widthpf = none;
		result->minuspf = none;
		result->typepf = none;
	}
	return (result);
}

int			ft_printf(const char *str, ...)
{
	int		result;
	char	*st;
	va_list	args;

	result = 0;
	st = (char*)str;
	va_start(args, str);
	ft_pr_result(st, args, &result);
	va_end(args);
	return (result);
}
