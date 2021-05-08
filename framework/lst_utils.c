#include "libunit.h"

int	ft_setptr(void *dest, void *p)
{
	*(uintptr_t *)dest = (uintptr_t)p;
	return (!!p);
}

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
	if (g_start)
	{
		new->start = 0;
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
	}
	else
	{
		new->start = 1;
		new->prev = new;
	}
	new->prev->next = new;
	*lst = new;
}

t_clist	*ft_clstnew(void *data)
{
	t_clist	*new;

	if (!ft_setptr(&new, malloc(sizeof(t_clist))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_free(t_clist **lst, t_clist *next, void *data)
{
	free(*lst);
	free(data);
	*lst = next;
}

void	lst_clear(t_clist *lst)
{
	if (!lst)
		return ;
	while (!lst->start)
		lst_free(&lst, lst->next, lst->data);
	lst_free(&lst, lst->next, lst->data);
}