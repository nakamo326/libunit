#include "../cases.h"

int	isprint_basic_test2(void)
{
	int	c;

	c = 'a';
	while (c <= 'z')
	{
		if (!!ft_isprint(c) != !!isprint(c))
			return (-1);
		c++;
	}
	return (0);
}
