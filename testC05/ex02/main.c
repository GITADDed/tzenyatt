#include <stdio.h>
#include <limits.h>

int ft_iterative_power(int n, int p);
int main()
{
	printf("power(-1, -1) == 0\n");
   printf("Answer: %d\n", ft_iterative_power(-1, -1));
   printf("power(-2, -2147483648) == 0\n");
   printf("Answer: %d\n", ft_iterative_power(-2, -2147483648));
   printf("power(-2147483648, 0) == 1\n");
   printf("Answer: %d\n", ft_iterative_power(-2147483648, 0));
   printf("power(0, 0) == 1\n");
   printf("Answer: %d\n", ft_iterative_power(0, 0));
   printf("power(1, 2147483647) == 1\n");
   printf("Answer: %d\n", ft_iterative_power(1, INT_MAX));
   printf("power(2, 0) == 1\n");
   printf("Answer: %d\n", ft_iterative_power(2, 0));
   printf("power(3, 1) == 3\n");
   printf("Answer: %d\n", ft_iterative_power(3, 1));
   printf("power(4, 3) == 64\n");
   printf("Answer: %d\n", ft_iterative_power(4, 3));
   printf("power(-5, 3) == -125\n");
   printf("Answer: %d\n", ft_iterative_power(-5, 3));
   printf("power(12, -3) == 0\n");
   printf("Answer: %d\n", ft_iterative_power(12, -3));
   printf("power(13, 7) == 62748517\n");
   printf("Answer: %d\n", ft_iterative_power(13, 7));
}
