#include "ft_printf.h"

static void			init_digit(char digits[11])
{
	int i;

	i = 0;
	while (i < 10)
	{
		digits[i] = '0' + i;
		i++;
	}
}

static int			ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void				print_num(int n)
{
	char		digits[11];
	int			num[12];
	int			i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	init_digit(digits);
	if (n < 0)
		write(1, "-", 1);
	while (n != 0)
	{
		num[i] = ft_abs(n % 10);
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digits[num[i]], 1);
		i--;
	}
}

void				print_unum(unsigned int n)
{
	char		digits[11];
	int			num[12];
	int			i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	init_digit(digits);
	while (n != 0)
	{
		num[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digits[num[i]], 1);
		i--;
	}
}

void            print_string(char *string)
{
    char *str;

    str = string;
    while (*str)
    {
        write(1, str, 1);
        ++str;
    }
}

void print_sixteen_base_num_memory(unsigned long long int num)
{
    char base[17] = "0123456789abcdef\0";
    char answer[15];
    int i;
    
    i = 16;
    if (num == 0)
    {
        write(1, "0x0", 1);
        return ;
    }
    while (num != 0)
    {
        answer[i] = base[num % 16];
        num /= 16;
        i--;   
    }
    i++;
    write(1, "0x", 2);
    while (i < 17)
    {
        write(1, &answer[i], 1);
        i++;
    }
    
}

void print_sixteen_base_num(unsigned int num, char size)
{
    char base[2][17] = {"0123456789ABCDEF\0", "0123456789abcdef\0"};
    char answer[5];
    int num_size;
    int i;
    
    i = 4;
    num_size = 0;
    if (size == 'x')
        num_size = 1;
    if (num == 0)
    {
        write(1, "0x0", 1);
        return ;
    }
    while (num != 0)
    {
        answer[i] = base[num_size][num % 16];
        num /= 16;
        i--;   
    }
    i++;
    write(1, "0x", 2);
    while (i < 5)
    {
        write(1, &answer[i], 1);
        i++;
    }
    
}
