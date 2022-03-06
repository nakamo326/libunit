#include "../cases.h"

int	free_literal_test(void)
{
	void	*p;

	p = "abc";
	ft_free(&p);
	if (!p)
		return (0);
	else
		return (-1);
}
