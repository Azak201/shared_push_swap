
#include <push_swap.h>

void	ft_dlstdelone(t_dlist *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del (lst -> content);
		free (lst);
	}
}
