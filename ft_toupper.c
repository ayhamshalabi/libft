#include "libft.h"

/*Converts a lowercase letter to its corresponding uppercase character.*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
