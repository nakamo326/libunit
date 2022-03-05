#include "../cases.h"

int	over_long2(void)
{
	const char	*s = "-92233720368547758081";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
