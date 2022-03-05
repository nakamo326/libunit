#include "../cases.h"

int	isprint_basic_test(void)
{
	int	c;

	c = 'A';
	while (c <= 'Z')
	{
		if (!!ft_isprint(c) != !!isprint(c))
			return (-1);
		c++;
	}
	return (0);
}
