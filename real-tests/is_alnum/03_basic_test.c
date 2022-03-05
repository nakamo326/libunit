#include "../cases.h"

int	alnum_basic_test3(void)
{
	const int	c = '\0';

	if (!!ft_isalnum(c) == !!isalnum(c))
		return (0);
	else
		return (-1);
}
