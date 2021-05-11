#include "toupper_tests.h"

int	toupper_basic_test(void)
{
	int	c;

	c = 'a';
	while (c <= 'z')
	{
		if (ft_toupper(c) != toupper(c))
			return (-1);
		c++;
	}
	return (0);
}
