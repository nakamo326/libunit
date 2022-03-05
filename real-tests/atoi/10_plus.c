#include "../cases.h"

int	plus(void)
{
	const char	*s = "+2147483647";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
