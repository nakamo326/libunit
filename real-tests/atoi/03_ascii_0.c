#include "../cases.h"

int	ascii_0(void)
{
	const char	*s = "\0";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
