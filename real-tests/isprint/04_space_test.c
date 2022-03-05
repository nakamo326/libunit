#include "../cases.h"

int	isprint_space(void)
{
	const int	c = ' ';

	if (!!ft_isprint(c) == !!isprint(c))
		return (0);
	else
		return (-1);
}
