#include "tolower_tests.h"

int	tolower_basic_test(void)
{
	int	c;

	c = 'A';
	while (c <= 'Z')
	{
		if (ft_tolower(c) != tolower(c))
			return (-1);
		c++;
	}
	return (0);
}
