#include "ft_list_bonus.h"

void	*ft_clst_next(t_clist **lst)
{
	void	*data;

	data = (*lst)->data;
	*lst = (*lst)->next;
	return (data);
}
