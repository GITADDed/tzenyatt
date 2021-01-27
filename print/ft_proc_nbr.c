#include "ft_printf.h"

int		ft_proc_di(t_printf *prc, va_list args)
{
	int			result;
	intmax_t	nbr;
	char		sign;

	result = 0;
	sign = none;
	nbr = (int)va_arg(args, int);
	if (nbr < 0)
	{
		sign = '-';
		nbr *= -1;
	}
	result += ft_pr_wp_nbr(prc, nbr, 10, sign);
	return (result);
}

int		ft_proc_ux(t_printf *prc, va_list args)
{
	int			result;
	uintmax_t	nbr;

	result = 0;
	nbr = (unsigned int)va_arg(args, int);
	result += ft_pr_wp_nbr(prc, nbr, prc->typepf == 'u' ? 10 : 16, none);
	return (result);
}

int		ft_proc_p(t_printf *prc, va_list args)
{
	int		result;
	size_t	nbr;

	result = 0;
	nbr = va_arg(args, unsigned long);
	result += ft_pr_wp_nbr(prc, (uintmax_t)nbr, 16, none);
	return (result + 2);
}
