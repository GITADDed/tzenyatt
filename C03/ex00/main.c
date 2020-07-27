#include <stdio.h>
#include <string.h>

int  ft_strcmp(char *s1, char *s2);

int main()
{
	char a[] = "Hesoyam1";
	char b[] = "hesoyam1";
	printf("EX00>>>>>>>>>>>>>>\n\n\nMUST BE : diff = %d, s1 = %s, s2 = %s\n >>>>>>>>>>>>>>>>>>>>>> \n", strcmp(a, b), a, b);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s\n\n\n\n", ft_strcmp(a , b), a, b);
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s\n >>>>>>>>>>>>>>>>>>>>>> \n", strcmp(b , a), b, a);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s\n\n\n\n", ft_strcmp(b , a), b, a);
	char a1[] = "Luke, I am your father !";
	char b1[] = "Luke, I am your father !";
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s\n >>>>>>>>>>>>>>>>>>>>>>>>\n", strcmp(a1 , b1), a1, b1);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s\n\n\n\n\n\n", ft_strcmp(a1 , b1), a1, b1);
	char a2[] = "";
	char b2[] = "V means vendetta!dsadasdadad";
	printf("MUST BE : diff = %d, s1 = %s, s2 = %s\n >>>>>>>>>>>>>>>>>>>>>>>>\n", strcmp(a2, b2), a2, b2);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s\n\n###################################\n##################################\n\n", ft_strcmp(a2 , b2), a2, b2);
}
