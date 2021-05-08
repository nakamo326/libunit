#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstsize;
	t_list	*current;

	lstsize = 0;
	if (!lst)
		return (0);
	lstsize++;
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		lstsize++;
	}
	return (lstsize);
}
