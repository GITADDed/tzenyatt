#include <stdio.h>
#include <string.h>

int  ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	unsigned int n = 8;
	char a[] = "Hesoyam1";
	char b[] = "hesoyam1";
	printf("EX01\n>>>>>>>>>>>>>>\n\n\nMUST BE : diff = %d, s1 = %s, s2 = %s, n = %d\n\n", strncmp(a, b, n), a, b, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncmp(a , b, n), a, b, n);
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s, n = %d\n\n", strncmp(b , a, n), b, a, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncmp(b , a, n), b, a, n);
	char a1[] = "Luke, I am your father !";
	char b1[] = "Luke, I am your father !";
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s, n = %d\n", strncmp(a1 , b1, n), a1, b1, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncmp(a1 , b1, n), a1, b1, n);
	n = -1;
	char a2[] = "1234";
	char b2[] = "123";
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s, n = %d\n", strncmp(a2, b2, n), a2, b2, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncmp(a2 , b2, n), a2, b2, n);
	n = 20;
	printf("MUST BE If n > len s1 or s2 : diff = %d, s1 = %s, s2 = %s, n = %d\n", strncmp(a2, b2, n), a2, b2, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n##################################################\n##################################################\n\n", ft_strncmp(a2 , b2, n), a2, b2, n);
}
