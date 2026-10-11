#include "libft.h"

/*Computes the length of a string, excluding the terminating null byte ('\0').*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
