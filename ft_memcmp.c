#include "libft.h"

/*Compares the first n bytes of the memory areas s1 and s2 byte-by-byte.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*last;

	first = (const unsigned char *)s1;
	last = (const unsigned char *)s2;
	while (n--)
	{
		if (*first != *last)
			return (*first - *last);
		first++;
		last++;
	}
	return (0);
}
