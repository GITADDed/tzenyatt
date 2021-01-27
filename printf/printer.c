#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	long sign;
	long num;

	sign = -1;
	num = 0;
	while (*str == ' ' || *str == '\v' || *str == '\t'
	|| *str == '\f' || *str == '\r' || *str == '\n')
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str != '+' && *str != '-' && *str < 48 && *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 - (*str - 48);
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
		++str;
	}
	return (num * sign);
}

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

void print_spaces(int n)
{
    int i;

    i = 0;
    while (i++ < n)
        write(1, " ", 1);
}

int num_size(int n)
{
    int i;

    i = 1;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

void flag_parser(int n, char *point_to_flag)
{
    char *p_to_max_size;
    int size;
    int min_size;

    min_size = 0;
    if (*point_to_flag == '-')
    {
        p_to_max_size = point_to_flag + 1;
        while (!ft_strchr(".di", *point_to_flag))
            point_to_flag++;
        if (*point_to_flag == '.')
            min_size = ft_atoi(++point_to_flag);
        size = print_num(n, min_size);
        print_spaces(ft_atoi(p_to_max_size) - size + 1);
    }
    else
    {
        if (*point_to_flag == '0')
        {
                print_num(n, ft_atoi(++point_to_flag));
                return ;
        }
        p_to_max_size = point_to_flag;
        while (!ft_strchr(".di", *point_to_flag))
            point_to_flag++;
        if (*point_to_flag == '.')
            min_size = ft_atoi(++point_to_flag);
        size = num_size(n);
        if (size < min_size)
            size = min_size;
        print_spaces(ft_atoi(p_to_max_size) - size + 1);
        print_num(n, min_size);
    }        
}

int				print_num(int n, int min_size)
{
	char		digits[11];
	int			num[12];
	int			i;
    int         size;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
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
    size = i;
	i--;
    while (size++ < min_size)
        write(1, "0", 1);
	while (i >= 0)
	{
		write(1, &digits[num[i]], 1);
		i--;
	}
    return (size);
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
