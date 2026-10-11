#include "libft.h"

/*Checks if the given character belongs to the 7-bit ASCII character set (0-127).*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
