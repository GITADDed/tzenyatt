#include <stdio.h>
#include <limits.h>

int ft_recursive_factorial(int n);
int main()
{
	printf("factorial(-1) == 0\n");
   printf("Answer: %d\n", ft_recursive_factorial(-1));
   printf("factorial(-2) == 0\n");
   printf("Answer: %d\n", ft_recursive_factorial(-2));
   printf("factorial(-2147483648) == 0\n");
   printf("Answer: %d\n", ft_recursive_factorial(-2147483648));
   printf("factorial(0) == 1\n");
   printf("Answer: %d\n", ft_recursive_factorial(0));
   printf("factorial(1) == 1\n");
   printf("Answer: %d\n", ft_recursive_factorial(1));
   printf("factorial(2) == 2\n");
   printf("Answer: %d\n", ft_recursive_factorial(2));
   printf("factorial(3) == 6\n");
   printf("Answer: %d\n", ft_recursive_factorial(3));
   printf("factorial(4) == 24\n");
   printf("Answer: %d\n", ft_recursive_factorial(4));
   printf("factorial(5) == 120\n");
   printf("Answer: %d\n", ft_recursive_factorial(5));
   printf("factorial(12) == 479001600\n");
   printf("Answer: %d\n", ft_recursive_factorial(12));
   printf("factorial(13) == 6227020800 (OVERFLOW)\n");
   printf("Answer: %d\n", ft_recursive_factorial(13));
}
