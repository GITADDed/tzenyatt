#include "ft_printf.h"

int		ft_proc_c(t_printf *prc, va_list args)
{
	int		result;
	char	chr;

	result = 0;
	if (prc->typepf == 'c')
		chr = va_arg(args, int);
	else
		chr = '%';
	if (prc->minuspf != '-')
		result += ft_pr_wid_str(prc, 1);
	ft_putchar(chr);
	prc->zeropf = none;
	if (prc->minuspf == '-')
		result += ft_pr_wid_str(prc, 1);
	return (++result);
}

int		ft_proc_s(t_printf *prc, va_list args)
{
	int		result;
	char	*str;
	char	*buf;

	result = 0;
	str = va_arg(args, char*);
	buf = str == NULL ? "(null)" : str;
	if (buf == NULL)
		result = -1;
	else
	{
		if (prc->precisionpf != none || prc->minuspf != none)
			prc->zeropf = none;
		prc->precisionpf = prc->precisionpf < 0 ? ft_strlen(buf) :
				prc->precisionpf;
		if (prc->precisionpf > ft_strlen(buf))
			prc->precisionpf = ft_strlen(buf);
		if (prc->minuspf != '-')
			result += ft_pr_wid_str(prc, prc->precisionpf);
		result += ft_pr_prec_str(prc, buf);
		if (prc->minuspf == '-')
			result += ft_pr_wid_str(prc, prc->precisionpf);
	}
	return (result);
}
