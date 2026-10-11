#include "libft.h"

/*Fills the first n bytes of the memory area pointed to by s with constant byte c.*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
