 #include "ft_printf.h"

char		ft_parce_flag(t_printf *prc, char **str)
{
	char	result;

	result = 't';
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			prc->minuspf = '-';
		else if (**str == '0')
			prc->zeropf = '0';
		++(*str);
	}
	if (**str == '\0')
		result = 'f';
	return (result);
}

char		ft_parce_width(t_printf *prc, char **str, va_list args)
{
	char	result;

	result = 't';
	while (**str >= '0' && **str <= '9')
	{
		if (prc->widthpf == none)
			prc->widthpf = 0;
		prc->widthpf = prc->widthpf * 10 + (**str - '0');
		++(*str);
	}
	if (**str == '*' && prc->widthpf == none)
	{
		prc->widthpf = va_arg(args, int);
		++(*str);
		if (prc->widthpf < 0)
		{
			prc->minuspf = '-';
			prc->zeropf = none;
			prc->widthpf *= -1;
		}
	}
	if (**str == '\0')
		result = 'f';
	return (result);
}

char		ft_parce_prec(t_printf *prc, char **str, va_list args)
{
	char result;

	result = 't';
	if (**str == '.')
	{
		++(*str);
		prc->precisionpf = 0;
		while (**str >= '0' && **str <= '9')
		{
			if (prc->precisionpf == none)
				prc->precisionpf = 0;
			prc->precisionpf = prc->precisionpf * 10 + (**str - '0');
			++(*str);
		}
		if (**str == '*')
		{
			prc->precisionpf = va_arg(args, int);
			++(*str);
			if (prc->precisionpf < 0)
				prc->precisionpf = none;
		}
		if (**str == '\0')
			result = 'f';
	}
	return (result);
}

t_printf	*ft_get_spec(char **str, va_list args)
{
	t_printf	*prc;
	char		free_parce;

	free_parce = 'f';
	prc = ft_init_spec();
	if (prc != NULL)
	{
		if (ft_parce_flag(prc, str) == 'f' || ft_parce_width(prc, str, args)
		== 'f' || ft_parce_prec(prc, str, args) == 'f')
			free_parce = 't';
		if (**str != 'c' && **str != 's' && **str != 'p' && **str != 'd' &&
		**str != 'i' && **str != 'u' && **str != 'x' && **str != 'X' && **str
		!= '%')
			free_parce = 't';
		else
			prc->typepf = *((*str)++);
	}
	if (free_parce == 't')
	{
		free(prc);
		prc = NULL;
	}
	return (prc);
}
