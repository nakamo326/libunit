#include "../cases.h"

int	hyphen(void)
{
	char	*s;

	s = "-";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
