#include <stdio.h>
int ft_fibonacci(int index);
int main()
 {
   printf("1. Должно быть 0 - ");
   printf("%d\n", ft_fibonacci(0));
   printf("2. Должно быть 1 - ");
   printf("%d\n", ft_fibonacci(1));
   printf("3. Должно быть 1 - ");
   printf("%d\n", ft_fibonacci(2));
   printf("4. Должно быть 2 - ");
   printf("%d\n", ft_fibonacci(3));
   printf("4. Должно быть 3 - ");
   printf("%d\n", ft_fibonacci(4));
   printf("4. Должно быть 5 - ");
   printf("%d\n", ft_fibonacci(5));
   printf("4. Должно быть 8 - ");
   printf("%d\n", ft_fibonacci(6));
   printf("4. Должно быть 13 - ");
   printf("%d\n", ft_fibonacci(7));
   printf("4. Должно быть 21 - ");
   printf("%d\n", ft_fibonacci(8));
   printf("4. Должно быть 34 - ");
   printf("%d\n", ft_fibonacci(9));
   printf("4. Должно быть 55 - ");
   printf("%d\n", ft_fibonacci(10));
   printf("4. Должно быть 89 - ");
   printf("%d\n", ft_fibonacci(11));
   printf("4. Должно быть 144 - ");
   printf("%d\n", ft_fibonacci(12));
   return 0;
 }
