#include <stdio.h>
#include <limits.h>

int ft_is_prime(int nb);
int main()
{
printf("%d", ft_is_prime(-1));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(1));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(0));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(-2));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(2));
   printf("  must be 1");
   printf("\n%d", ft_is_prime(4));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(3));
   printf("  must be 1");
   printf("\n%d", ft_is_prime(5));
   printf("  must be 1");
   printf("\n%d", ft_is_prime(17));
   printf("  must be 1");
   printf("\n%d", ft_is_prime(18));
   printf("  must be 0");
   printf("\n%d", ft_is_prime(2147483647));
   printf("  must be 1");
   return 0;
}
