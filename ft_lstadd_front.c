#include "libft.h"

/*Adds the node new to the beginning of the list lst.*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
