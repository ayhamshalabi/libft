#include "libft.h"

/*Checks if the given character is alphanumeric (either a letter or a digit).*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
