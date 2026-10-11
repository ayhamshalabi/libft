#include "libft.h"

/*Checks whether character c is present in the character set string set.*/
static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*Counts consecutive leading characters of string s1 that exist in set.*/
static size_t	front_count(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s1[i] && in_set(s1[i], set))
	{
		count++;
		i++;
	}
	return (count);
}

/*Counts consecutive trailing characters of string s1 that exist in set.*/
static size_t	back_count(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = ft_strlen(s1);
	while (i > 0 && in_set(s1[i - 1], set))
	{
		count++;
		i--;
	}
	return (count);
}

/*Allocates and returns a copy of s1 with characters in set trimmed from start and end.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*ptr_start;
	size_t	front;
	size_t	back;
	size_t	ptr_len;

	if (!s1 || !set)
		return (NULL);
	front = front_count(s1, set);
	if (front != ft_strlen(s1))
		back = back_count(s1, set);
	else
		back = 0;
	ptr_len = ft_strlen(s1) - (front + back);
	ptr = malloc(ptr_len + 1);
	if (!ptr)
		return (NULL);
	ptr_start = ptr;
	s1 += front;
	while (ptr_len--)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ptr_start);
}
