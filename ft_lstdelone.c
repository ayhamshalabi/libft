#include "libft.h"

/*Frees the memory of node lst's content using del, and frees the node itself.*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
