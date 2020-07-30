#include <stdio.h>
#include <limits.h>

int ft_sqrt(int n);
int main()
{
	printf("ft_sqrt(-2147483648) == 0\n");
   printf("%d\n", ft_sqrt(INT_MIN));
   printf("ft_sqrt(-1) == 0\n");
   printf("%d\n", ft_sqrt(-1));
   printf("ft_sqrt(0) == 0\n");
   printf("%d\n", ft_sqrt(0));
   printf("ft_sqrt(1) == 1\n");
   printf("%d\n", ft_sqrt(1));
   printf("ft_sqrt(2147483647) == 0\n");
   printf("%d\n", ft_sqrt(INT_MAX));
   printf("ft_sqrt(5) == 0\n");
   printf("%d\n", ft_sqrt(5));
   printf("ft_sqrt(2) == 0\n");
   printf("%d\n", ft_sqrt(2));
   printf("ft_sqrt(3) == 0\n");
   printf("%d\n", ft_sqrt(3));
   printf("ft_sqrt(7) == 0\n");
   printf("%d\n", ft_sqrt(7));
   printf("ft_sqrt(4) == 2\n");
   printf("%d\n", ft_sqrt(4));
   printf("ft_sqrt(9) == 3\n");
   printf("%d\n", ft_sqrt(9));
   printf("ft_sqrt(36) == 6\n");
   printf("%d\n", ft_sqrt(36));
   printf("ft_sqrt(169) == 13\n");
   printf("%d\n", ft_sqrt(169));
   printf("ft_sqrt(144) == 12\n");
   printf("%d\n", ft_sqrt(144));
}
