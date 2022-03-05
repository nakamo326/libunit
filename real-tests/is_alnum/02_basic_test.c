#include "../cases.h"

int	alnum_basic_test2(void)
{
	const int	c = '1';

	if (!!ft_isalnum(c) == !!isalnum(c))
		return (0);
	else
		return (-1);
}
