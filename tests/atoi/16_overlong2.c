#include "../cases.h"

int	over_long2(void)
{
	char	*s;

	s = "-92233720368547758081";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
