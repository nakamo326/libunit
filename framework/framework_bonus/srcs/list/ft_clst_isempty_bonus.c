#include "ft_list_bonus.h"
#include <stdbool.h>

bool	ft_clst_isempty(t_clist *lst)
{
	return (lst == lst->next);
}
