#include "../cases.h"

int	over_intmin(void)
{
	const char	*s = "-2147483649";	

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
