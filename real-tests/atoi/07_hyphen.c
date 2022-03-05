#include "../cases.h"

int	hyphen(void)
{
	const char	*s = "-";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
