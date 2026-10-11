#include "libft.h"

/*Checks if the given character is printable, including the space character.*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
