#include "../cases.h"

int	error_a(void)
{
	char	*s;

	s = "a";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
