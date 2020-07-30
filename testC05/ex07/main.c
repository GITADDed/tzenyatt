#include <stdio.h>
#include <limits.h>

int ft_find_next_prime(int n);
int main()
{
	printf("ft_find_next_prime(-2147483648) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(-2147483648));
   printf("ft_find_next_prime(-256) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(-256));
   printf("ft_find_next_prime(-1) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(-1));
   printf("ft_find_next_prime(0) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(0));
   printf("ft_find_next_prime(1) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(1));
   printf("ft_find_next_prime(2) == 2\n");
   printf("Answer: %d\n", ft_find_next_prime(2));
   printf("ft_find_next_prime(4) == 5\n");
   printf("Answer: %d\n", ft_find_next_prime(4));
   printf("ft_find_next_prime(5) == 5\n");
   printf("Answer: %d\n", ft_find_next_prime(5));
   printf("ft_find_next_prime(2147483647) == 2147483647\n");
   printf("Answer: %d\n", ft_find_next_prime(2147483647));
   printf("ft_find_next_prime(110) == 113\n");
   printf("Answer: %d\n", ft_find_next_prime(110));
   printf("ft_find_next_prime(113) == 113\n");
   printf("Answer: %d\n", ft_find_next_prime(113));
   printf("ft_find_next_prime(104) == 107\n");
   printf("Answer: %d\n", ft_find_next_prime(104));
   printf("ft_find_next_prime(107) == 107\n");
   printf("Answer: %d\n", ft_find_next_prime(107));
}
