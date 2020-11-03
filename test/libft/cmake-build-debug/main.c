#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
	char str1[100] = "the cake is";
	char *str2 = " a lie !";
	ft_strlcat(str1, str2, 100);
}