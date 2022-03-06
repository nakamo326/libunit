#include "ft_list_bonus.h"
#include <stdbool.h>

bool	ft_clst_isbegin(t_clist *lst)
{
	return (!lst->prev->data);
}
