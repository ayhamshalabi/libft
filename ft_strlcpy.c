#include "libft.h"

/*Copies up to dstsize - 1 characters from string src to dst, NUL-terminating the result.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
