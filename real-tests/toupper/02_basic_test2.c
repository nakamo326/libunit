#include "../cases.h"

int toupper_basic_test2(void)
{
	int c;

	c = 'A';
	while (c <= 'Z')
	{
		if (ft_toupper(c) != toupper(c))
			return (-1);
		c++;
	}
	return (0);
}
