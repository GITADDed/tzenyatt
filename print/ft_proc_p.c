#include "ft_printf.h"

int		ft_pr_wid_str(t_printf *prc, int strlen)
{
	int result;

	result = 0;
	prc->widthpf -= strlen;
	while (result < prc->widthpf)
	{
		if (prc->zeropf == '0')
			ft_putchar('0');
		else
			ft_putchar(' ');
		++result;
	}
	return (result);
}

int		ft_pr_prec_str(t_printf *prc, char *str)
{
	int result;

	result = 0;
	while (result < prc->precisionpf && *str != '\0')
	{
		ft_putchar(*(str++));
		++result;
	}
	return (result);
}

int		ft_pr_wp_nbr(t_printf *prc, uintmax_t nbr, int base, char sign)
{
	int result;
	int nlen;

	result = 0;
	if (prc->precisionpf != none || prc->minuspf != none)
		prc->zeropf = none;
	nlen = nbr == 0 && prc->precisionpf == 0 ? 0 : ft_nlen_b(nbr, base);
	if (prc->minuspf != '-')
		result += ft_pr_width(prc, nlen, sign);
	result += ft_pr_prec(prc, nlen, sign);
	if (nbr == 0 && prc->precisionpf != 0)
		ft_putchar('0');
	if (prc->typepf == 'X')
		ft_putnbr_b(nbr, base, "0123456789ABCDEF");
	else
		ft_putnbr_b(nbr, base, "0123456789abcdef");
	if (prc->minuspf == '-')
		result += ft_pr_width(prc, nlen, sign);
	result += nlen;
	return (result);
}

int		ft_pr_width(t_printf *prc, int len, char sign)
{
	int result;

	result = 0;
	if (sign != none && prc->zeropf != none && prc->precisionpf == none &&
	prc->minuspf == none)
		ft_putchar(sign);
	if (prc->widthpf > len && prc->widthpf > prc->precisionpf)
	{
		prc->widthpf -= prc->precisionpf > len ? prc->precisionpf : len;
		prc->widthpf -= sign == none ? 0 : 1;
		prc->widthpf -= prc->typepf == 'p' ? 2 : 0;
		while (result++ < prc->widthpf)
		{
			if (prc->zeropf == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	return (result > prc->widthpf && result != 0 ? --result : result);
}

int		ft_pr_prec(t_printf *prc, int len, char sign)
{
	int result;

	result = 0;
	if (sign != none && (prc->zeropf == none || prc->precisionpf != none ||
		prc->minuspf == '-'))
		ft_putchar(sign);
	if (prc->typepf == 'p')
		ft_putstr("0x");
	if (prc->precisionpf != none && prc->precisionpf > len)
	{
		while (result < prc->precisionpf - len)
		{
			ft_putchar('0');
			++result;
		}
	}
	result += sign == none ? 0 : 1;
	return (result);
}
