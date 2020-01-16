#include "inc/libmx.h"
#include <string.h>
#include <stdio.h>

void mx_print_list(t_list **head) {
    for (t_list *walker = *head; walker != NULL; walker = walker->next) {
        printf("%s\n", *((char **)walker->data));
    }
}

int main()
{
	printf("\033[0;31m");
	printf("                       UTILS PACK\n");
	printf("\n\n");
	printf("\033[0m");


	// {
	// printf("\033[0;32m");
	// printf("//************// CASE for MX_PRINT_UNICODE \\\\*************|\n");
	// printf("\033[0m");
	// printf("--------------USER OUTPUT --------------------------------|\n");
	// mx_print_unicode("0x0061");
	// printf("\033[0;32m");
	// printf("//*************\\\\**************************//*************|\n");
	// printf("\033[0m");
	// printf("\n\n");
	// }


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_PRINT_STRARR \\\\**************|\n");
	printf("\033[0m");
	char *arr[] = {"I", "dont", "like", "your", "code", "!", NULL};
	char *delim = "*";
	char *test = "I*dont*like*your*code*!\n";
	printf("--------------USER OUTPUT --------------------------------|\n");
	mx_print_strarr(arr, delim);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%s\n", test);
	printf("\033[0;32m");
	printf("//*************\\\\*************************//**************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_NBR_TO_HEX \\\\****************|\n");
	printf("\033[0m");
	char *num;
	char *num1;
	char *num2;
	char *num3;
	char *num4;
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", num = mx_nbr_to_hex(171));
	printf("%s\n", num1 = mx_nbr_to_hex(100));
	printf("%s\n", num2 = mx_nbr_to_hex(123));
	printf("%s\n", num3 = mx_nbr_to_hex(140732918889176));
	printf("%s\n", num4 = mx_nbr_to_hex(9223372036854775807));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("ab\n64\n7b\n7ffeefa37ad8\n7fffffffffffffff\n");
	printf("\033[0;32m");
	printf("//************\\\\************************//****************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_PRINTINT \\\\******************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	mx_printint(244);
	printf("\n");
	mx_printint(2147483647);
	printf("\n");
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%d\n", 244);
	printf("%d\n", 2147483647);
	printf("\033[0;32m");
	printf("//************\\\\**********************//******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_ITOA \\\\**********************|\n");
	printf("\033[0m");
	char *itoa;
	char *itoa1;
	char *itoa2;
	char *itoa3;
	char *itoa4;
	char *itoa5;
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", itoa = mx_itoa(-895));
	printf("%s\n", itoa1 = mx_itoa(-2147483648));
	printf("%s\n", itoa2 = mx_itoa(1953587560));
	printf("%s\n", itoa3 = mx_itoa(2147483647));
	printf("%s\n", itoa4 = mx_itoa(1));
	printf("%s\n", itoa5 = mx_itoa(0));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("-895\n-2147483648\n1953587560\n2147483647\n1\n0\n");
	printf("\033[0;32m");
	printf("//************\\\\******************//**********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	printf("\033[0;31m");
	printf("                       STRING PACK\n");
	printf("\n\n");
	printf("\033[0m");

	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_SWAP_CHAR \\\\*****************|\n");
	printf("\033[0m");
	char st[] = "ONE";
	printf("--------------USER OUTPUT --------------------------------|\n");
	mx_swap_char(&st[0], &st[1]);
	printf("%s\n", st);
	mx_swap_char(&st[1], &st[2]);
	printf("%s\n", st);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("NOE\nNEO\n");
	printf("\033[0;32m");
	printf("//************\\\\************************//****************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STR_REVERSE \\\\***************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	char str1[] = "dratsab revo emag";
	char str[] = "KCUF";
	mx_str_reverse(str);
	printf("%s\n", str);
	mx_str_reverse(str1);
	printf("%s\n", str1);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("FUCK\ngame over bastard\n");
	printf("\033[0;32m");
	printf("//************\\\\*************************//***************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("//************// CASE for MX_STRDEL \\\\********************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	char *str2 = mx_strdup("lolkek");
	printf("%s\n", str2);
	mx_strdel(&str2);
	printf("%s\n", str2);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("lolkek\n(null)\n");
	printf("\033[0;32m");
	printf("//************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_DEL_STRARR \\\\****************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	int i = 0;
	char **str3 = (char **)malloc(sizeof(char*) *  6);
	while (i < 5)
	{
		if (i % 2 == 0)
			str3[i] = mx_strdup("ds");
		else
			str3[i] = mx_strdup("kek");
		i++;
	}
	str3[i] = NULL;
	i = 0;
	for (;str3[i]; i++)
		printf("%s\n", str3[i]);
	mx_del_strarr(&str3);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("ds\nkek\nds\nkek\nds\n");
	printf("\033[0;32m");
	printf("//************\\\\**************************//**************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_GET_CHAR_INDEX \\\\************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	char *str4 = "dont read my commits";
	char s = 'r';
	char s1 = 'd';
	char s2 = 'c';
	printf("%d\n", mx_get_char_index(str4, s));
	printf("%d\n", mx_get_char_index(str4, s1));
	printf("%d\n", mx_get_char_index(str4, s2));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("5\n0\n13\n");
	printf("\033[0;32m");
	printf("//************\\\\****************************//************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("//************// CASE for MX_STRNCPY \\\\*******************|\n");
	
	char src[] = "I like code";
	char dst[] = "sosihfsfs s q		";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", mx_strncpy(dst, src, 14));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%s\n", strncpy(dst, src, 14));
	
	printf("//************\\\\*********************//*******************|\n");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STRNDUP \\\\*******************|\n");
	printf("\033[0m");
	// char *s = "Do not hate me for my code";
	char *sq = "Do not hate me for my code";
	// char *temp;
	// char *temp1;
	// char *temp2;
	char *temp3;
	char *temp4;
	char *temp5;
	printf("--------------USER OUTPUT --------------------------------|\n");
	// printf("%s\n", temp = mx_strndup(s, 10));
	// printf("%s\n", temp1 = mx_strndup(s, -1));
	// printf("%s\n", temp2 = mx_strndup(s, 100));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%s\n", temp3 = strndup(sq, 10));
	printf("%s\n", temp4 = strndup(sq, -1));
	printf("%s\n", temp5 = strndup(sq, 100));
	printf("\033[0;32m");
	printf("//************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STRCAT \\\\********************|\n");
	printf("\033[0m");
	char s1[30] = "Lemon, ";
	char s2[7] = "Apple";
	char s3[30] = "Lemon, ";
	printf("--------------USER OUTPUT --------------------------------|\n");
	mx_strcat(s1, s2);
	strcat(s3, s2);
	printf("%s\n", s1);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%s\n", s3);
	printf("\033[0;32m");
	printf("//************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STRSTR \\\\********************|\n");
	printf("\033[0m");
	char haystack[] = "To ezz 4 me, brro";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", mx_strstr(haystack, "ezu"));
	printf("%s\n", mx_strstr(haystack, "me"));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("%s\n", strstr(haystack, "ezu"));
	printf("%s\n", strstr(haystack, "me"));
	printf("\033[0;32m");
	printf("//************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_GET_SUBSTR_INDEX \\\\**********|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%d\n", mx_get_substr_index("McDonalds", "Don"));
	printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
	printf("%d\n", mx_get_substr_index("McDonalds", "Donatello"));
	printf("%d\n", mx_get_substr_index("McDonalds", NULL));
	printf("%d\n", mx_get_substr_index(NULL, "Don"));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("2\n3\n-1\n-2\n-2\n");
	printf("\033[0;32m");
	printf("//************\\\\******************************//**********|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_COUNT_SUBSTR \\\\**************|\n");
	printf("\033[0m");
	char str[] = "yo, yoyo, yo Neoyo";
	char sub[] = "yo";
	char str1[] = " 	oooo  	";
	char sub1[] = "o";
	char str2[] = " 	oooo  	yo";
	char sub2[] = "\0";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%d\n", mx_count_substr(str, sub));
	printf("%d\n", mx_count_substr(str1, sub1));
	printf("%d\n", mx_count_substr(str2, sub2));
	printf("%d\n", mx_count_substr(str2, NULL));
	printf("%d\n", mx_count_substr(NULL, sub2));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("5\n4\n0\n-1\n-1\n");
	printf("\033[0;32m");
	printf("//************\\\\**************************//**************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_COUNT_WORDS \\\\**************|\n");
	printf("\033[0m");
	char str7[] = " follow   * the white rabbit ";
	char str[] = "";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%d\n", mx_count_words(str7, ' ')); //5
	printf("%d\n", mx_count_words(str7, '*')); //2
	printf("%d\n", mx_count_words(str7, 'x')); //1
	printf("%d\n", mx_count_words(str, ' ')); //0
	printf("%d\n", mx_count_words(NULL, 'x')); //-1
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("5\n2\n1\n0\n-1\n");
	printf("\033[0;32m");
	printf("//************\\\\**************************//**************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STRTRIM \\\\*******************|\n");
	printf("\033[0m");
	char *name = "	\f    My     name...	is  \t  Neo	\t\n";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", name = mx_strtrim(name));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("My     name...	is  \t  Neo\n");
	printf("\033[0;32m");
	printf("//************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_DEL_EXTRA_SPACES \\\\**********|\n");
	printf("\033[0m");
	char *name1 = "\f My    name... \r \n \t  \tis  \t    Neo \t\n";
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", name1 = mx_del_extra_spaces(name1));
	printf("%d\n", mx_strlen(name1)); //17
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("My name... is Neo\n");
	printf("17\n");
	printf("\033[0;32m");
	printf("//************\\\\******************************//**********|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	{
	// printf("\033[0;32m");
	// printf("//************// CASE for MX_STRSPLIT \\\\******************|\n");
	// printf("\033[0m");
	// char string[] = "**Good bye,**Mr.*Anderson.****"; //21
	// int j = 0;
	// char **result = mx_strsplit(string, ' ');
	// char **result1 = mx_strsplit(string, '*');
	// char **result2 = mx_strsplit(string, '.');
	// printf("--------------USER OUTPUT --------------------------------|\n");
	// while (result[j])
	// 	printf("%s\n",result[j++]);
	// j = 0;
	// printf("\n");
	// while (result1[j])
	// 	printf("%s\n",result1[j++]);
	// printf("\n");
	// j = 0;
	// while (result2[j])
	// 	printf("%s\n",result2[j++]);
	// printf("--------------TEST OUTPUT --------------------------------|\n");
	// printf("**Good\nbye,**Mr.*Anderson.****\n\n");
	// printf("Good bye,\nMr.\nAnderson.\n\n");
	// printf("**Good bye,**Mr.\n*Anderson.\n****\n\n");
	// printf("\033[0;32m");
	// printf("//************\\\\**********************//******************|\n");
	// printf("\033[0m");
	// printf("\n\n");
	}


	{
	printf("\033[0;32m");
	printf("//************// CASE for MX_STRJOIN \\\\*******************|\n");
	printf("\033[0m");
	char *ss1 = "this";
	char *ss2 = "dodge ";
	char *ss3 = NULL;
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n", ss1 = mx_strjoin(ss2, ss1));
	printf("%s\n", ss3 = mx_strjoin(ss3, ss3));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("dodge this\n(null)\n");
	printf("\033[0;32m");
	printf("//************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	char *temp;
	char *temp1;
	printf("\033[0;32m");
	printf("//************// CASE for MX_FILE_TO_STR \\\\***************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT --------------------------------|\n");
	temp = mx_file_to_str("test.txt");
	printf("%s\n", temp);
	temp1 = mx_file_to_str("test1.txt");
	printf("%s\n", temp1);
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("The number 2,147,483,647\n(or hexadecimal 7FFF,FFFF16)\n(null)\n");
	printf("\033[0;32m");
	printf("//************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}
/*
	{
	printf("\033[0;32m");
	printf("/ CASE for MX_REPLACE_SUBSTR \\\\************|\n");
	printf("\033[0m");
	char *temp;
	char *temp1;
	char *temp2;
	printf("--------------USER OUTPUT --------------------------------|\n");
	printf("%s\n",temp = mx_replace_substr("McDonalds", "alds", "uts"));
	printf("%s\n",temp1 = mx_replace_substr("Ururu turu", "ru", "ta"));
	printf("%s\n",temp2 = mx_replace_substr("ka Kabakakaka na", "ka", "na"));
	printf("%s\n",mx_replace_substr(NULL, "ru", "ta"));
	printf("%s\n",mx_replace_substr("Ururu turu", NULL, "ta"));
	printf("%s\n",mx_replace_substr("Ururu turu", "ru", NULL));
	printf("--------------TEST OUTPUT --------------------------------|\n");
	printf("McDonuts\nUtata tuta\nna Kabananana na\n(null)\n(null)\n(null)\n");
	printf("\033[0;32m");
	printf("\n");
	printf("\033[0m");
	printf("\n\n");
	}
*/
	printf("\033[0;31m");
	printf("                       MEMORY PACK\n");
	printf("\n\n");
	printf("\033[0m");

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMSET \\\\********************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT ------------------------------|\n");
	unsigned char b[] = "123456789";
	unsigned char b1[] = "123456789";
	size_t len = 9;
	mx_memset(b, 65, len);
	printf("%s\n", b);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	memset(b1, 65, len);
	printf("%s\n", b1);
	printf("\033[0;32m");
	printf("************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMCPY \\\\********************|\n");
	printf("\033[0m");
	const char src[50] = "Test Test Test";
	char dest[50];
	const char src1[50] = "Test Test Test";
	char dest1[50];
	printf("--------------USER OUTPUT ------------------------------|\n");
	mx_memcpy(dest, src, strlen(src)+1);
	printf("%s\n", dest);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	memcpy(dest1, src1, strlen(src1)+1);
	printf("%s\n", dest1);
	printf("\033[0;32m");
	printf("************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMCCPY \\\\*******************|\n");
	printf("\033[0m");
	const char src[50] = "Test Memccpy Test Test memccpy";
	char dest[50];
	char dest1[50];
	char dest2[50];
	char dest3[50];
	char dest4[50];
	const char src1[50] = "Test Memccpy Test Test memccpy";
	char dest5[50];
	printf("--------------USER OUTPUT ------------------------------|\n");
	mx_memccpy(dest, src, 77, strlen(src)+1); //M
	printf("%s\n", dest);
	mx_memccpy(dest1, src, 84, strlen(src)+1); //T
	printf("%s\n", dest1);
	mx_memccpy(dest2, src, 97, strlen(src)+1); //a
	printf("%s\n", dest2);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	memccpy(dest3, src1, 77, strlen(src1)+1); //M
	printf("%s\n", dest3);
	memccpy(dest4, src, 84, strlen(src)+1); //T
	printf("%s\n", dest4);
	memccpy(dest5, src, 97, strlen(src)+1); //a
	printf("%s\n", dest5);
	printf("\033[0;32m");
	printf("************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMCMP \\\\********************|\n");
	printf("\033[0m");
	char s1[] = "abcEw";
	char s2[] = "abcdOPDEF";
	char s3[] = "abcEq";
	int temp;
	printf("--------------USER OUTPUT ------------------------------|\n");
	printf("%d\n", temp = mx_memcmp(s1, s2, 6));
	printf("%d\n", temp = mx_memcmp(s1, s3, 12));
	printf("%d\n", temp = mx_memcmp(s1, s3, 3));
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("%d\n", temp = memcmp(s1, s2, 6));
	printf("%d\n", temp = memcmp(s1, s3, 12));
	printf("%d\n", temp = memcmp(s1, s3, 3));
	printf("\033[0;32m");
	printf("************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMCHR \\\\********************|\n");
	printf("\033[0m");
	const char s1[] = "Rick && Morty";
	const char s2[] = "Rick && Morty";
	const char *s3;
	const char *s4;
	const char c = '&';
	s3 = mx_memchr(s1, c, mx_strlen(s1) + 1);
	s4 = memchr(s2, c, mx_strlen(s2) + 1);
	printf("--------------USER OUTPUT ------------------------------|\n");
	printf("%s\n", s3);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("%s\n", s4);
	printf("\033[0;32m");
	printf("************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMMEM \\\\********************|\n");
	printf("\033[0m");
	const char big[] = "Rick && Morty";
	const char little[] = "R";
	const char little1[] = "F";
	const char little2[] = "&&";
	const char *s1 = mx_memmem(big, mx_strlen(big), little, mx_strlen(little));
	const char *s2 = mx_memmem(big, mx_strlen(big), little1, mx_strlen(little1));
	const char *s3 = mx_memmem(big, mx_strlen(big), little2, mx_strlen(little2));
	const char *s4 = memmem(big, mx_strlen(big), little, mx_strlen(little));
	const char *s5 = mx_memmem(big, mx_strlen(big), little1, mx_strlen(little1));
	const char *s6 = mx_memmem(big, mx_strlen(big), little2, mx_strlen(little2));
	
	printf("--------------USER OUTPUT ------------------------------|\n");
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("%s\n", s4);
	printf("%s\n", s5);
	printf("%s\n", s6);
	printf("\033[0;32m");
	printf("************\\\\********************//********************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMRCHR \\\\*******************|\n");
	printf("\033[0m");
	const char *s = mx_memrchr("Trinity", 'i', 7);
	const char *s1 = mx_memrchr("Trinity", 'M', 7);
	printf("--------------USER OUTPUT ------------------------------|\n");
	printf("%s\n", s); ////returns "ity"
	printf("%s\n", s1); //returns NULL
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("ity\n(null)\n");
	printf("\033[0;32m");
	printf("************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_MEMMOVE \\\\*******************|\n");
	printf("\033[0m");
	char dest[] = "oldstring";
	const char src[]  = "newstring";
	char dest1[] = "oldstring";
	const char src1[]  = "newstring";
	mx_memmove(dest, src, 9);
	memmove(dest1, src1, 9);
	printf("--------------USER OUTPUT ------------------------------|\n");
	printf("%s\n", dest);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("%s\n", dest1);
	printf("\033[0;32m");
	printf("************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	{
	printf("\033[0;32m");
	printf("************// CASE for MX_REALLOC \\\\*******************|\n");
	printf("\033[0m");
	char *str;
	printf("--------------USER OUTPUT ------------------------------|\n");
	/* Initial memory allocation */
   	str = (char *) malloc(17);
	mx_strcpy(str, "Wifi password = ");
	printf("%s\n", str);
   	/* Reallocating memory */
   	str = (char *)mx_realloc(str, 50);
	mx_strcat(str, "let the force be with you");
	printf("%s\n", str);

	free(str);
	printf("--------------TEST OUTPUT ------------------------------|\n");
	{
	/* Initial memory allocation */
   	str = (char *) malloc(17);
	strcpy(str, "Wifi password = ");
	printf("%s\n", str);

   	/* Reallocating memory */
   	str = (char *)realloc(str, 50);
	strcat(str, "let the force be with you");
	printf("%s\n", str);

	free(str);
	}
	printf("\033[0;32m");
	printf("************\\\\*********************//*******************|\n");
	printf("\033[0m");
	printf("\n\n");
	}


	printf("\033[0;31m");
	printf("                       LIST PACK\n");
	printf("\n\n");
	printf("\033[0m");

	{
	printf("\033[0;32m");
	printf("//************// CASE for LIST_PACK \\\\***************|\n");
	printf("\033[0m");
	printf("--------------USER OUTPUT ------------------------------|\n");
	t_list *head = NULL;

    char *s1 = "55555";
    char *s2 = "4444";
    char *s3 = "333";
    char *s4 = "22";
    char *s5 = "1";

    mx_push_front(&head, &s1);
    mx_push_front(&head, &s2);
    mx_push_front(&head, &s3);
    mx_push_front(&head, &s4);
    mx_push_front(&head, &s5);
    mx_push_back(&head, &s1);
    mx_push_back(&head, &s2);
    mx_push_back(&head, &s3);
    mx_push_back(&head, &s4);
    mx_push_back(&head, &s5);

    mx_print_list(&head);

	printf("size of list = %d\n", mx_list_size(head));
	printf("\n");
	mx_pop_back(&head);
	mx_pop_front(&head);
	mx_print_list(&head);
	printf("size of list = %d\n", mx_list_size(head));
	printf("--------------TEST OUTPUT ------------------------------|\n");
	printf("1\n22\n333\n4444\n55555\n55555\n4444\n333\n22\n1\n");
	printf("size of list = 10\n\n");
	printf("22\n333\n4444\n55555\n55555\n4444\n333\n22\n");
	printf("size of list = 8\n");
	printf("\033[0;32m");
	printf("//************\\\\*************************//***************|\n");
	printf("\033[0m");
	printf("\n\n");
	}

	system("leaks -q out");
	return 0;
}
