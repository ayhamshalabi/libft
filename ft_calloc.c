#include "libft.h"

/*Allocates memory for an array of nmemb elements of size bytes each and sets it to zero.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
		total = 1;
	else
		total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
