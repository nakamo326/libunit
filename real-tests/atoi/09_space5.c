#include "../cases.h"

int	space5(void)
{
	const char	*s = "\t\v\f\r\n \f-06050";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
