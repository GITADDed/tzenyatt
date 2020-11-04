#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
	char *n = "\t\v\f\r\n \f-06050";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("%d\n", i1);
	printf("%d\n", i2);
}