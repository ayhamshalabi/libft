#include "libft.h"

/*Checks if the given character is an alphabetic letter (A-Z or a-z).*/
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
