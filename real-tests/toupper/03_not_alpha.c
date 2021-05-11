#include "toupper_tests.h"

int toupper_not_alpha(void)
{
	int c;

	c = '[';
	while (c < 'a')
	{
		if (ft_toupper(c) != toupper(c))
			return (-1);
		c++;
	}
	return (0);
}
