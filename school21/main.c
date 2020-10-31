#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "libft.h"


int main(void)
{
	int ch = 0;
	char *str1 = "Cloring Cal";
	char *str2 = "htunetClorosCloringhuceoalhcpcirch";
	char *str3 = "Cloring";
	char *str4 = "Cloring";
	char *str5 = "htunetClorosCloringhuceoalhcpcirch";
	char *str6 = "Cloring";
	char *str7 = "6743.33";
	char *str8 = "-874.e";
	char *str9 = "           -894.e";
	char *str10 = " ---+++--x874.e";
	char *str11 = " b----++++-77.e";
	char *str12 = "b8374";
	char *str13 = " -b334";
	char *str14 = "+874.e";
	char *str15 = " -2147483649";
	char *str16 = "+2147483648";
	char *str18 = malloc(sizeof(char) * 12);
	char *str19 = malloc(sizeof(char) * 12);
	char *str20 = malloc(sizeof(char) * 20);
	char *str21 = malloc(sizeof(char) * 20);
//	char *str17 = 0;


	printf("strrchr #####################\n");
//	TODO: normal test_1
	printf("your func: %c\n", *ft_strrchr(str1, ch));
	printf("original func: %c\n", *strrchr(str1, ch));
//	TODO: without 'a' test musn't be working
	printf("your func: %s\n", ft_strrchr(str4, ch));
	printf("your func: %s\n", strrchr(str4, ch));


	printf("strnstr ####################\n");
//	TODO: normal test_2
	printf("your func: %s\n", ft_strnstr(str5, str6, 40));
	printf("orig func: %s\n", strnstr(str2, str3, 40));
//	TODO: test_3 with short round
	printf("your func: %s\n", ft_strnstr(str5, str6, 4));
	printf("orig func: %s\n", strnstr(str2, str3, 4));
//	TODO: test_4 with changing strings
	printf("your func: %s\n", ft_strnstr(str6, str5, 40));
	printf("orig func: %s\n", strnstr(str3, str2, 40));


	printf("strncmp ####################\n");
//	TODO: normal test_5
	printf("your func: %d\n", ft_strncmp(str3, str4, 5));
	printf("orig func: %d\n", strncmp(str3, str4, 5));
//	TODO: test_6 searching round bigger then len strings
	printf("your func: %d\n", ft_strncmp(str3, str4, 100));
	printf("orig func: %d\n", strncmp(str3, str4, 100));
//	TODO: test_7 with not equal letters
	printf("your func: %d\n", ft_strncmp(str3, str5, 5));
	printf("orig func: %d\n", strncmp(str3, str5, 5));
//	TODO: test_8 with not equal letters and searching round bigger then len
// strings
	printf("your func: %d\n", ft_strncmp(str1, str3, 1000));
	printf("orig func: %d\n", strncmp(str1, str3, 1000));


	printf("ATOI ####################\n");
//	TODO: normal test_9
	printf("your func: %d\n", ft_atoi(str7));
	printf("orig func: %d\n", atoi(str7));
//	TODO: test_10 with minus
	printf("your func: %d\n", ft_atoi(str8));
	printf("orig func: %d\n", atoi(str8));
//	TODO: test_11 with plus
	printf("your func: %d\n", ft_atoi(str14));
	printf("orig func: %d\n", atoi(str14));
//	TODO: test_12 with spaces
	printf("your func: %d\n", ft_atoi(str9));
	printf("orig func: %d\n", atoi(str9));
//	TODO: test_13 with letter after signs
	printf("your func: %d\n", ft_atoi(str10));
	printf("orig func: %d\n", atoi(str10));
//	TODO: test_14 with letter after space and before signs
	printf("your func: %d\n", ft_atoi(str11));
	printf("orig func: %d\n", atoi(str11));
//	TODO: test_15 with letter at the begining
	printf("your func: %d\n", ft_atoi(str12));
	printf("orig func: %d\n", atoi(str12));
//	TODO: test_16 with lettr between signs plus and minus
	printf("your func: %d\n", ft_atoi(str13));
	printf("orig func: %d\n", atoi(str13));
//	TODO: test_17 with the smallest num
	printf("your func: %d\n", ft_atoi(str15));
	printf("orig func: %d\n", atoi(str15));
//	TODO: test_18 with the biggest num
	printf("your func: %d\n", ft_atoi(str16));
	printf("orig func: %d\n", atoi(str16));
//	TODO: test_19 with null
//	printf("your func: %d\n", ft_atoi(str17));
//	printf("orig func: %d\n", atoi(str17));


	printf("ISALPHA ####################\n");
//	TODO: test_20 is alpha
	printf("your func: %d\n", ft_isalpha(101));
	printf("orig func: %d\n", isalpha(101));
//	TODO: test_21 is non alpha
	printf("your func: %d\n", ft_isalpha(35));
	printf("orig func: %d\n", isalpha(35));
//	TODO: test_22 negativ value
	printf("your func: %d\n", ft_isalpha(-1));
	printf("orig func: %d\n", isalpha(-1));


	printf("ISDIGIT ####################\n");
//	TODO: test_23 is digit
	printf("your func: %d\n", ft_isdigit(49));
	printf("orig func: %d\n", isdigit(49));
//	TODO: test_24 is non alpha
	printf("your func: %d\n", ft_isdigit(35));
	printf("orig func: %d\n", isdigit(35));
//	TODO: test_25 negativ value
	printf("your func: %d\n", ft_isdigit(-1));
	printf("orig func: %d\n", isdigit(-1));


	for (int i = 0; i < 15; ++i) {
		*(str18 + i) = 53;
		*(str19 + i) = 53;
		*(str20 + i) = 53;
		*(str21 + i) = 53;
	}
	*(str18 + 15) = '\0';
	*(str19 + 15) = '\0';
	*(str20 + 15) = '\0';
	*(str21 + 15) = '\0';
	printf("MEMSET ####################\n");
//	TODO: Normal test_26 with * from malloc
	printf("your func: %s\n", ft_memset(str18, 48, 12));
	printf("orig func: %s\n", memset(str19, 48, 12));
//	TODO: test_27 with 0 bytes
	printf("your func: %s\n", ft_memset(str18, 48, 0));
	printf("orig func: %s\n", memset(str19, 48, (0)));


	printf("BZERO ####################\n");
//	TODO: Normal test_28 with * from malloc
	ft_bzero(str20, 12);
	bzero(str21, 12);
	printf("your func: %s\n", str20);
	printf("orig func: %s\n", str21);
//	TODO: test_29 with 0 bytes
	ft_bzero(str20, 0);
	bzero(str21, (0));
	printf("your func: %s\n", str20);
	printf("orig func: %s\n", str21);


	printf("MEMCPY ####################\n");
	char str22[20] = "Hesoyam33\0";
	char str23[20] = "oliksoooo12o\0";
	char str32[20] = "Hesoyam33\0";
	char str33[20] = "oliksoooo12o\0";
	char str24[20] = "Sabstrsoooo12o\0";
	char str25[20] = "olik\0";
	char str26[20] = "Sabstrsoooo12o\0";
	char str27[20] = "olik\0";
	char str28[20] = "Sabstrsoooo12o\0";
	char str29[20] = "olik\0";
	char str30[20] = "Sabstrsoooo12o\0";
	char str31[20] = "olik\0";
//	char str42[20] = "Sabstrsoooo12o\0";
//	char str41[20] = "olik\0";
//	char str35[20] = "olik\0";
//	char str36[20] = "olik\0";
	char str37[20] = "Sabstrsoooo12o\0";
	char str38[20] = "olik\0";
	char str39[20] = "Sabstrsoooo12o\0";
	char str40[20] = "olik\0";
//	char *str_null = 0;
//	TODO MEMCPY: Normal test_30											 CHECKED
	ft_memcpy(str32, str33, 4);
	printf("your func: %s\n", str32);
	memcpy(str22, str23, 4);
	printf("orig func: %s\n", str22);
//	TODO MEMCPY: test_31 where len(dest) < size < len(src) 				 CHECKED
 	ft_memcpy(str25, str24, 11);
 	printf("your func: %s\n", str25);
	memcpy(str27, str26, 11);
	printf("orig func: %s\n", str27);
//	TODO MEMCPY: test_32 where len(dest) > size > len(src)				 CHECKED
 	ft_memcpy(str28, str29, 11);
 	printf("your func: %s\n", str28);
	memcpy(str30, str31, 11);
	printf("orig func: %s\n", str30);
//	TODO MEMCPY: test_33 where dest = NULL							   UNCHECKED
//	ft_memcpy(str_null, str35, 11);
// 	printf("your func: %s\n", str_null);
//	memcpy(str_null, str36, 11);
//	printf("orig func: %s\n", str_null);
//	TODO MEMCPY: test_34 where src = NULL 							   UNCHECKED
//	ft_memcpy(str35, str_null, 11);
// 	printf("your func: %s\n", str35);
//	memcpy(str36, str_null, 11);
//	printf("orig func: %s\n", str36);
//	TODO MEMCPY: test_35 where size = 0 								 CHECKED
	ft_memcpy(str37, str38, 0);
 	printf("your func: %s\n", str37);
	memcpy(str39, str40, 0);
	printf("orig func: %s\n", str39);


	char str43[20] = "Hesoyam33\0";
	char str44[20] = "oliksoooo12o\0";
	char str45[20] = "Hesoyam33\0";
	char str46[20] = "oliksoooo12o\0";
	char str47[20] = "Sabstrsoooo12o\0";
	char str48[20] = "olik\0";
	char str49[20] = "Sabstrsoooo12o\0";
	char str50[20] = "olik\0";
	char str51[20] = "Sabstrsoooo12o\0";
	char str52[20] = "olik\0";
	char str53[20] = "Sabstrsoooo12o\0";
	char str54[20] = "olik\0";
//	char str55[20] = "Sabstrsoooo12o\0";
//	char str56[20] = "olik\0";
//	char str57[20] = "olik\0";
//	char str58[20] = "olik\0";
	char str59[20] = "Sabstrsoooo12o\0";
	char str60[20] = "olik\0";
	char str61[20] = "Sabstrsoooo12o\0";
	char str62[20] = "olik\0";
	char str63[20] = "Sabstrsoooo12o\0";
	char str64[20] = "olik\0";
	char str65[20] = "Sabstrsoooo12o\0";
	char str66[20] = "olik\0";
	printf("MEMCCPY ####################\n");
	//	TODO MEMCCPY: Normal test_36									 CHECKED
	ft_memccpy(str43, str44, 's', 8);
	printf("your func: %s\n", str43);
	memccpy(str45, str46, 's', 8);
	printf("orig func: %s\n", str45);
//	TODO MEMCCPY: test_37 where len(dest) < size < len(src)				 CHECKED
 	ft_memccpy(str48, str47, 'o', 8);
 	printf("your func: %s\n", str48);
	memccpy(str50, str49, 'o', 8);
	printf("orig func: %s\n", str50);
//	TODO MEMCCPY: test_38 where len(dest) > size > len(src)				 CHECKED
 	ft_memccpy(str51, str52, 'a', 8);
 	printf("your func: %s\n", str51);
	memccpy(str53, str54, 'a', 8);
	printf("orig func: %s\n", str53);
//	TODO MEMCCPY: test_39 where dest = NULL							   UNCHECKED
//	ft_memccpy(str_null, str35, 11);
//	memccpy(str_null, str36, 11);
//	TODO MEMCCPY: test_40 where src = NULL 							   UNCHECKED
//	ft_memccpy(str35, str_null, 11);
//	memccpy(str36, str_null, 11);
//	TODO MEMCCPY: test_41 where size = 0								 CHECKED
	ft_memccpy(str59, str60, 'n', 0);
 	printf("your func: %s\n", str59);
	memccpy(str61, str62, 'n', 0);
	printf("orig func: %s\n", str61);
//	TODO MEMCCPY: test_42 where char was before size					 CHECKED
	ft_memccpy(str64, str63, 't', 10);
	printf("your func: %s\n", str64);
	memccpy(str66, str65, 't', 10);
	printf("orig func: %s\n", str66);
//	TODO MEMCCPY: test_43 where char is negative						 CHECKED
//	ft_memccpy(str64, str63, 't', -5);
//	printf("your func: %s\n", str64);
//	memccpy(str66, str65, 't', -5);
//	printf("orig func: %s\n", str66);


	char *str67 = malloc(sizeof(char) * 20);
	char *str68 = str67 + 4;
	char *str69 = malloc(sizeof(char) * 20);
	char *str70 = str69 + 4;
	for (int j = 0; j < 15; ++j) {
		*(str67 + j) = 'f';
		*(str68 + j) = 'A';
		*(str69 + j) = 'f';
		*(str70 + j) = 'A';
	}
	*(str67 + 15) = '\0';
	*(str68 + 15) = '\0';
	*(str69 + 15) = '\0';
	*(str70 + 15) = '\0';
	printf("MEMMOVE ####################\n");
//	TODO MEMOVE: normal test_44
	printf("your func: %s\n", ft_memmove(str67, str68, 2));
	printf("orig func: %s\n", memmove(str69, str70, 2));
//	TODO MEMOVE: test_45 with null str								   UNCHECKED
//	printf("orig func: %s\n", ft_memmove(str69, str_null, 2));


	printf("MEMCHR ####################\n");
//	TODO MEMCHR: test_46 with letter after string
	char str71[30] = "Found letter a\0";
	char str72[30] = "Found letter a\0";

	*(str72 + 17) = 'K';
	*(str71 + 17) = 'K';
	printf("your func: %s\n", ft_memchr(str71, 'K', 20));
	printf("orig func: %s\n", memchr(str72, 'K', 20));


	printf("MEMCMP ####################\n");
	char str73[30] = "Found letter a\0";
	char str74[30] = "Found letter a\0";

	*(str73 + 16) = 'A';
	*(str74 + 16) = 'B';
//	TODO MEMCMP: test_47 with letter after null-terminator
	printf("your func: %d\n", ft_memcmp(str73, str74, 17));
	printf("orig func: %d\n", memcmp(str73, str74, 17));


	printf("STRLCPY ####################\n");
	char str75[7] = "Privet\0";
	char str76[5] = "Poka\0";
	char str77[7] = "Privet\0";
	char str78[5] = "Poka\0";

//	TODO STRLCPY: test_48 normal
	printf("your func: %lu\n", ft_strlcpy(str76, str75, 5));
	printf("what in str: %s\n", str76);
	printf("orig func: %lu\n", strlcpy(str78, str77, 5));
	printf("what in str: %s\n", str78);


	printf("STRLCAT ####################\n");
	char str79[7] = "Privet\0";
	char str80[11] = "Poka\0";
	char str81[7] = "Privet\0";
	char str82[11] = "Poka\0";

	//	TODO STRLCAT: test_49 normal
	printf("your func: %lu\n", ft_strlcat(str80, str79, 11));
	printf("what in str: %s\n", str80);
	printf("orig func: %lu\n", strlcat(str82, str81, 11));
	printf("what in str: %s\n", str82);

	char *str83 = (char *)ft_calloc(5, sizeof(char));
	*str83 = 'c';
	*(str83 + 1) = 'o';
	*(str83 + 2) = 'p';
	*(str83 + 3) = 'y';
	printf("%s\n", str83);

	printf("%s\n", ft_strdup(str83));

	return 0;
}
