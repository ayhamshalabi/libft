#include "libft.h"

/*Counts the number of nodes in the list lst.*/
unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
