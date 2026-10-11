#include "libft.h"

/*Counts the number of words in string s delimited by character c.*/
static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

/*Measures the length of the current word in string s up to delimiter c or null terminator.*/
static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/*Frees all previously allocated word substrings and the parent array upon allocation error.*/
static void	free_res(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
}

/*Allocates and populates each word substring into the result array res.*/
static int	fill_res(char **res, char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = word_len(s, c);
		res[i] = malloc(len + 1);
		if (!res[i])
		{
			free_res(res, i);
			return (0);
		}
		ft_strlcpy(res[i], s, len + 1);
		i++;
		s += len;
	}
	res[i] = NULL;
	return (1);
}

/*Splits string s into an array of strings using delimiter character c.*/
char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_res(res, s, c))
		return (NULL);
	return (res);
}
