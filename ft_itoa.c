#include "libft.h"

/*Calculates the total character length required to represent integer n in decimal, including sign.*/
static size_t	num_len(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*Converts the integer n into a null-terminated string representation.*/
char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	len;

	nb = n;
	len = num_len(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	res[--len] = nb + '0';
	if (n < 0)
		res[0] = '-';
	return (res);
}
