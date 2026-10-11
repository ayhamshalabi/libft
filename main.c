#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[1;34m"
#define YELLOW	"\033[1;33m"
#define RESET	"\033[0m"

/*Helper function to print colored PASS/FAIL status for a test assertion.*/
static void	test_check(const char *name, int condition)
{
	if (condition)
		printf("  %-25s %s[OK]%s\n", name, GREEN, RESET);
	else
		printf("  %-25s %s[KO]%s\n", name, RED, RESET);
}

/*Test callback for ft_strmapi: converts lowercase characters to uppercase.*/
static char	mapi_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*Test callback for ft_striteri: converts lowercase characters to uppercase in place.*/
static void	iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

/*Test mapping callback for ft_lstmap: duplicates string node content.*/
static void	*lstmap_dup(void *content)
{
	return (ft_strdup((char *)content));
}

/*Test deletion callback for ft_lstclear and ft_lstmap: frees node content.*/
static void	del_content(void *content)
{
	free(content);
}

/*Runs comprehensive unit tests for Part 1 standard Libc functions.*/
static void	test_part1(void)
{
	char	buf[30];
	char	buf2[30];
	char	*dup;
	void	*ptr;

	printf("\n%s=== PART 1: Libc Functions ===%s\n", BLUE, RESET);

	/*isalpha, isdigit, isalnum, isascii, isprint*/
	test_check("ft_isalpha", ft_isalpha('A') == 1 && ft_isalpha('z') == 1 && ft_isalpha('1') == 0);
	test_check("ft_isdigit", ft_isdigit('0') == 1 && ft_isdigit('9') == 1 && ft_isdigit('a') == 0);
	test_check("ft_isalnum", ft_isalnum('A') == 1 && ft_isalnum('5') == 1 && ft_isalnum('#') == 0);
	test_check("ft_isascii", ft_isascii(0) == 1 && ft_isascii(127) == 1 && ft_isascii(128) == 0);
	test_check("ft_isprint", ft_isprint(' ') == 1 && ft_isprint('~') == 1 && ft_isprint(31) == 0);

	/*strlen*/
	test_check("ft_strlen", ft_strlen("Hello") == 5 && ft_strlen("") == 0);

	/*memset, bzero*/
	ft_memset(buf, 'X', 5);
	buf[5] = '\0';
	test_check("ft_memset", strcmp(buf, "XXXXX") == 0);
	ft_bzero(buf, 5);
	test_check("ft_bzero", buf[0] == 0 && buf[4] == 0);

	/*memcpy, memmove*/
	ft_memcpy(buf, "ABCDE", 6);
	test_check("ft_memcpy", strcmp(buf, "ABCDE") == 0);
	ft_memcpy(buf, "123456789", 10);
	ft_memmove(buf + 2, buf, 5);
	test_check("ft_memmove (overlap)", strncmp(buf, "121234589", 9) == 0);

	/*strlcpy, strlcat*/
	memset(buf, 0, sizeof(buf));
	test_check("ft_strlcpy", ft_strlcpy(buf, "Hello", 6) == 5 && strcmp(buf, "Hello") == 0);
	test_check("ft_strlcat", ft_strlcat(buf, " World", 12) == 11 && strcmp(buf, "Hello World") == 0);

	/*toupper, tolower*/
	test_check("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('A') == 'A');
	test_check("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('a') == 'a');

	/*strchr, strrchr*/
	test_check("ft_strchr", ft_strchr("hello", 'e') != NULL && *ft_strchr("hello", 'e') == 'e');
	test_check("ft_strchr (null byte)", ft_strchr("hello", '\0') != NULL);
	test_check("ft_strrchr", ft_strrchr("hello world", 'o') != NULL && ft_strrchr("hello world", 'o') == ("hello world" + 7));

	/*strncmp, memchr, memcmp*/
	test_check("ft_strncmp", ft_strncmp("abc", "abd", 2) == 0 && ft_strncmp("abc", "abd", 3) < 0);
	test_check("ft_memchr", ft_memchr("abcdef", 'c', 5) != NULL && *(char *)ft_memchr("abcdef", 'c', 5) == 'c');
	test_check("ft_memcmp", ft_memcmp("abc", "abc", 3) == 0 && ft_memcmp("abc", "abd", 3) < 0);

	/*strnstr*/
	test_check("ft_strnstr", ft_strnstr("hello world", "world", 11) != NULL && strcmp(ft_strnstr("hello world", "world", 11), "world") == 0);
	test_check("ft_strnstr (len limit)", ft_strnstr("hello world", "world", 8) == NULL);
	test_check("ft_strnstr (empty)", strcmp(ft_strnstr("hello", "", 5), "hello") == 0);

	/*atoi*/
	test_check("ft_atoi (positive)", ft_atoi("  +123") == 123);
	test_check("ft_atoi (negative)", ft_atoi("  -123") == -123);
	test_check("ft_atoi (INT_MIN)", ft_atoi("-2147483648") == INT_MIN);
	test_check("ft_atoi (INT_MAX)", ft_atoi("2147483647") == INT_MAX);

	/*calloc, strdup*/
	ptr = ft_calloc(5, sizeof(int));
	memset(buf2, 0, 5 * sizeof(int));
	test_check("ft_calloc", ptr != NULL && memcmp(ptr, buf2, 5 * sizeof(int)) == 0);
	free(ptr);

	ptr = ft_calloc(0, 0);
	test_check("ft_calloc (0, 0)", ptr != NULL);
	free(ptr);

	dup = ft_strdup("Libft String");
	test_check("ft_strdup", dup != NULL && strcmp(dup, "Libft String") == 0);
	free(dup);
}

/*Runs comprehensive unit tests for Part 2 additional utility functions.*/
static void	test_part2(void)
{
	char	*str;
	char	**arr;
	char	iter_buf[10];

	printf("\n%s=== PART 2: Additional Functions ===%s\n", BLUE, RESET);

	/*substr*/
	str = ft_substr("hello world", 6, 5);
	test_check("ft_substr", str != NULL && strcmp(str, "world") == 0);
	free(str);

	str = ft_substr("test_string", 0, 1000000);
	test_check("ft_substr (large len)", str != NULL && strcmp(str, "test_string") == 0);
	free(str);

	/*strjoin*/
	str = ft_strjoin("Hello ", "World");
	test_check("ft_strjoin", str != NULL && strcmp(str, "Hello World") == 0);
	free(str);

	/*strtrim*/
	str = ft_strtrim("  --Custom Library--  ", " -");
	test_check("ft_strtrim", str != NULL && strcmp(str, "Custom Library") == 0);
	free(str);

	str = ft_strtrim("xxxx", "x");
	test_check("ft_strtrim (all trimmed)", str != NULL && strcmp(str, "") == 0);
	free(str);

	/*split*/
	arr = ft_split("   hello   world   custom  library  ", ' ');
	test_check("ft_split", arr != NULL && arr[0] != NULL && strcmp(arr[0], "hello") == 0
		&& arr[1] != NULL && strcmp(arr[1], "world") == 0
		&& arr[2] != NULL && strcmp(arr[2], "custom") == 0
		&& arr[3] != NULL && strcmp(arr[3], "library") == 0
		&& arr[4] == NULL);
	if (arr)
	{
		int i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}

	/*itoa*/
	str = ft_itoa(0);
	test_check("ft_itoa (0)", str != NULL && strcmp(str, "0") == 0);
	free(str);

	str = ft_itoa(-1234);
	test_check("ft_itoa (-1234)", str != NULL && strcmp(str, "-1234") == 0);
	free(str);

	str = ft_itoa(INT_MIN);
	test_check("ft_itoa (INT_MIN)", str != NULL && strcmp(str, "-2147483648") == 0);
	free(str);

	str = ft_itoa(INT_MAX);
	test_check("ft_itoa (INT_MAX)", str != NULL && strcmp(str, "2147483647") == 0);
	free(str);

	/*strmapi*/
	str = ft_strmapi("hello", mapi_upper);
	test_check("ft_strmapi", str != NULL && strcmp(str, "HELLO") == 0);
	free(str);

	/*striteri*/
	strcpy(iter_buf, "hello");
	ft_striteri(iter_buf, iteri_upper);
	test_check("ft_striteri", strcmp(iter_buf, "HELLO") == 0);

	/*fd functions visual check*/
	printf("  %sTesting ft_put*_fd outputs to stdout below:%s\n", YELLOW, RESET);
	printf("    ft_putchar_fd : ");
	ft_putchar_fd('X', 1);
	printf("\n    ft_putstr_fd  : ");
	ft_putstr_fd("Hello World!", 1);
	printf("\n    ft_putendl_fd : ");
	ft_putendl_fd("End of Line.", 1);
	printf("    ft_putnbr_fd  : ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
}

/*Runs comprehensive unit tests for Part 3 singly linked list functions.*/
static void	test_part3_bonus(void)
{
	t_list	*head;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*mapped;

	printf("\n%s=== PART 3: Linked List Functions ===%s\n", BLUE, RESET);

	head = NULL;
	n1 = ft_lstnew(ft_strdup("Node 1"));
	test_check("ft_lstnew", n1 != NULL && strcmp((char *)n1->content, "Node 1") == 0 && n1->next == NULL);

	/*lstadd_front*/
	ft_lstadd_front(&head, n1);
	test_check("ft_lstadd_front", head == n1);

	n2 = ft_lstnew(ft_strdup("Node 0"));
	ft_lstadd_front(&head, n2);
	test_check("ft_lstadd_front (2nd)", head == n2 && head->next == n1);

	/*lstsize*/
	test_check("ft_lstsize", ft_lstsize(head) == 2);

	/*lstlast*/
	test_check("ft_lstlast", ft_lstlast(head) == n1);

	/*lstadd_back*/
	n3 = ft_lstnew(ft_strdup("Node 2"));
	ft_lstadd_back(&head, n3);
	test_check("ft_lstadd_back", ft_lstlast(head) == n3 && ft_lstsize(head) == 3);

	/*lstmap*/
	mapped = ft_lstmap(head, lstmap_dup, del_content);
	test_check("ft_lstmap", mapped != NULL && ft_lstsize(mapped) == 3 && strcmp((char *)mapped->content, "Node 0") == 0);
	ft_lstclear(&mapped, del_content);

	/*lstclear*/
	ft_lstclear(&head, del_content);
	test_check("ft_lstclear", head == NULL);
}

/*Entry point executing all unit test suites for libft.*/
int	main(void)
{
	printf("%s========================================%s\n", YELLOW, RESET);
	printf("%s     LIBFT COMPREHENSIVE TEST SUITE     %s\n", YELLOW, RESET);
	printf("%s         Author: Ayham Shalabi          %s\n", YELLOW, RESET);
	printf("%s   https://github.com/ayhamshalabi      %s\n", YELLOW, RESET);
	printf("%s========================================%s\n", YELLOW, RESET);

	test_part1();
	test_part2();
	test_part3_bonus();

	printf("\n%s========================================%s\n", YELLOW, RESET);
	printf("%s   ALL 43 FUNCTIONS TEST SUITE DONE!    %s\n", GREEN, RESET);
	printf("%s========================================%s\n\n", YELLOW, RESET);
	return (0);
}
