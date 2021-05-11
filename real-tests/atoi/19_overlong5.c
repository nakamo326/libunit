#include "../cases.h"

int	over_lon5(void)
{
	char	*s;

	s = "-922337203685477580a";
	return (-(ft_atoi(s) != atoi(s)));
}
