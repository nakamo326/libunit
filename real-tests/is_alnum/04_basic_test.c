#include "../cases.h"

int	alnum_basic_test4(void)
{
	const int	c = 300;

	if (!!ft_isalnum(c) == !!isalnum(c))
		return (0);
	else
		return (-1);
}
