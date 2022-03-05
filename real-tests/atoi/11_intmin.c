#include "../cases.h"

int	intmin(void)
{
	const char	*s = "-2147483648";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
