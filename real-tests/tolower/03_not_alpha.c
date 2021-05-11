#include "../cases.h"

int	tolower_not_alpha(void)
{
	int	c;

	c = '[';
	while (c < 'a')
	{
		if (ft_tolower(c) != tolower(c))
			return (-1);
		c++;
	}
	return (0);
}
