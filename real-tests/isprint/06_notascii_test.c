#include "../cases.h"

int	isprint_not_ascii(void)
{
	const int	c = 555;

	if (!!ft_isprint(c) == !!isprint(c))
		return (0);
	else
		return (-1);
}
