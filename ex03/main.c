#include <stdio.h>
#include <string.h>

char  *ft_strncat(char *s1, char *s2, unsigned int n);

int main()
{
	unsigned int n = 8;
	char a[100] = "Hesoyam12";
	char b[100] = "hesoyam1";
	printf("EX03\n>>>>>>>>>>>>>>\n\n\nMUST BE : diff = %s, s1 = %s, s2 = %s, n = %d\n\n", strncat(a, b, n), a, b, n);
	char a1[100] = "Hesoyam12";
	char b1[100] = "hesoyam1";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncat(a1 , b1, n), a1, b1, n);
	char a3[100] = "Hesoyam12";
	char b3[100] = "hesoyam1";
	printf("MUST BE : diff = %s, s1 = %s, s2 = %s, n = %d\n\n", strncat(b3 , a3, n), b3, a3, n);
	char a9[100] = "Hesoyam12";
	char b9[100] = "hesoyam1";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncat(b9 , a9, n), b9, a9, n);
	char a4[100] = "Luke, I am your father !";
	char b4[100] = "Luke, I am your father !";
	printf("MUST BE : diff = %s, s1 = %s, s2 = %s, n = %d\n", strncat(a4 , b4, n), a4, b4, n);
	char a5[100] = "Luke, I am your father !";
	char b5[100] = "Luke, I am your father !";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncat(a5 , b5, n), a5, b5, n);
	n = 17;
	char a2[100] = "V means vendetta";
	char b2[100] = "V means vendetta!dsadasdadad";
	printf("MUST BE : diff = %s, s1 = %s, s2 = %s, n = %d\n", strncat(a2, b2, n), a2, b2, n);
	char a6[100] = "V means vendetta";
	char b6[100] = "V means vendetta!dsadasdadad";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncat(a6 , b6, n), a6, b6, n);
	char a12[100] = "";
	char b12[100] = "V means vendetta!dsadasdadad";
	printf("MUST BE : diff = %s, s1 = %s, s2 = %s, n = %d\n", strncat(a12, b12, n), a12, b12, n);
	char a16[100] = "";
	char b16[100] = "V means vendetta!dsadasdadad";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n", ft_strncat(a16 , b16, n), a16, b16, n);
	n = 100;
	char a7[100] = "V means vendetta";
	char b7[100] = "V means vendetta!dsadasdadad";
	printf("MUST BE If n > len s1 or s2 : diff = %s, s1 = %s, s2 = %s, n = %d\n", strncat(a7, b7, n), a7, b7, n);
	char a8[100] = "V means vendetta";
	char b8[100] = "V means vendetta!dsadasdadad";
	printf("WHAT RESULT : diff = %s, s1 = %s, s2 = %s, n = %d\n\n##################################################\n##################################################\n\n", ft_strncat(a8 , b8, n), a8, b8, n);
}
