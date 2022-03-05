#include "../cases.h"

int	isprint_stdspace(void)
{
	const int	c = '\t';

	if (!!ft_isprint(c) == !!isprint(c))
		return (0);
	else
		return (-1);
}
