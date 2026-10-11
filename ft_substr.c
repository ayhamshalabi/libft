#include "libft.h"

/*Allocates and returns a substring from string s starting at index start of length len.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*ptr_start;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr_start = ptr;
	s += start;
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (ptr_start);
}
