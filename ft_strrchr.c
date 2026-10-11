#include "libft.h"

/*Locates the last occurrence of character c in string s.*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occ = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_occ);
}
