#include "../cases.h"

int	alnum_basic_test(void)
{
	const int	c = 'a';

	if (!!ft_isalnum(c) == !!isalnum(c))
		return (0);
	else
		return (-1);
}
