#include "libft.h"

/*Converts the initial portion of the string pointed to by nptr to an integer.*/
int	ft_atoi(const char *nptr)
{
	int		is_negative;
	long	dest;

	is_negative = 1;
	dest = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		dest = dest * 10 + (*nptr - '0');
		nptr++;
	}
	return (dest * is_negative);
}
