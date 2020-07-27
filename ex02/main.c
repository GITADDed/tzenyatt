#include <stdio.h>
#include <string.h>

char *ft_strcat(char *s1, char *s2);

int main()
{
	int i = 0;
	char a[50] = "Hesoyam12";
	char b[50] = "hesoyam1";
	printf("EX01\n>>>>>>>>>>>>>>\n\n\nMUST BE :dest > result = %s, s1 = %s, s2 = %s\n\n", strcat(a, b), a, b);
	char a4[50] = "Hesoyam12";
	while (*(a + i))
		i++;
	if (*(a + i) == '\0')
		printf("OK\n and i = %d", i);
	i = 0;
	printf("WHAT RESULT : result = %s, s1 = %s, s2 = %s\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strcat(a4 , b), a4, b);
	while (*(a4 + i) != '\0')
		i++;
	if (*(a4 + i) == '\0')
		printf("OK\n and i = %d", i);
	printf("MUST BE :dest < src result = %s, s1 = %s, s2 = %s\n\n", strcat(b , a), b, a);
	printf("WHAT RESULT : result = %s, s1 = %s, s2 = %s\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strcat(b , a), b, a);
	char a1[100] = "Luke, I am your father !";
	char b1[100] = "Luke, I am your father !";
	printf("MUST BE : dest == src result = %s, s1 = %s, s2 = %s\n", strcat(a1 , b1), a1, b1);
	//a1 = "Luke, I am your father !";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strcat(a1 , b1), a1, b1);
	char a2[100] = "V means vendetta";
	char b2[100] = "V means vendetta!dsadasdadad";
	/*printf("MUST BE : result = %s, s1 = %s, s2 = %s\n", strcat(a2, b2), a2, b2);
	printf("WHAT RESULT : result = %s, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncmp(a2 , b2, n), a2, b2, n);
	printf("MUST BE If n > len s1 or s2 : diff = %d, s1 = %s, s2 = %s, n = %d\n", strncmp(a2, b2, n), a2, b2, n);
	printf("WHAT RESULT : diff = %d, s1 = %s, s2 = %s, n = %d\n\n##################################################\n##################################################\n\n", ft_strncmp(a2 , b2, n), a2, b2, n);
	*/
}
