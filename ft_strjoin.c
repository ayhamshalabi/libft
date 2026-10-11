#include "libft.h"

/*Allocates and returns a new string resulting from the concatenation of s1 and s2.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_start;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	ptr_start = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr_start);
}
