#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_nlen_b(uintmax_t nbr, int base)
{
	int result;

	result = 0;
	while (nbr >= 0)
	{
		nbr /= base;
		++result;
		if (nbr == 0)
			break ;
	}
	return (result);
}

void	ft_putnbr_b(uintmax_t nbr, int base, char *str)
{
	if (nbr == 0)
		return ;
	ft_putnbr_b(nbr / base, base, str);
	ft_putchar(str[nbr % base]);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
