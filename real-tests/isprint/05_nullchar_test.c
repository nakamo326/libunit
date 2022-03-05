#include "../cases.h"

int	isprint_null_char(void)
{
	const int	c = '\0';

	if (!!ft_isprint(c) == !!isprint(c))
		return (0);
	else
		return (-1);
}
