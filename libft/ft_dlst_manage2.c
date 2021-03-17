#include "libft.h"

t_dlst	*ft_dlst_addfront(t_dlst **lst, t_dlst *new)
{
	if (!lst)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (new);
	}
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
	return (new);
}
