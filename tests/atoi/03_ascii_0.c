#include "../cases.h"

int	ascii_0(void)
{
	char	*s;

	s = "\0";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
