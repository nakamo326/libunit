#include "../cases.h"

int	tolower_basic_test2(void)
{
	int c;

	c = 'a';
	while (c <= 'z')
	{
		if (ft_tolower(c) != tolower(c))
			return (-1);
		c++;
	}
	return (0);
}
