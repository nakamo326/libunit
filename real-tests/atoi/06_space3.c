#include "../cases.h"

int	space3(void)
{
	const char	*s = "3456  ";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
