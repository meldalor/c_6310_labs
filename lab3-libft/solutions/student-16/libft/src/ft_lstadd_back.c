#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = node;
}
