
#include <push_swap.h>

void	ft_dlstiter(t_dlist *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
