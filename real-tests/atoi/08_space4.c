#include "../cases.h"

int	space4(void)
{
	const char	*s = "\t\v\f\r\n \f- \f\t\n\r    06050";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
