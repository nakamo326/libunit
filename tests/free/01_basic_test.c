#include "../cases.h"

int	free_basic_test(void)
{
	void	*p;

	p = malloc(10);
	ft_free(&p);
	if (!p)
		return (0);
	else
		return (-1);
}
