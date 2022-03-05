#include "../cases.h"

int	alnum_basic_test5(void)
{
	const int	c = 48 + (1 << 20);

	if (!!ft_isalnum(c) == !!isalnum(c))
		return (0);
	else
		return (-1);
}
