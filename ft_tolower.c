#include "libft.h"

/*Converts an uppercase letter to its corresponding lowercase character.*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
