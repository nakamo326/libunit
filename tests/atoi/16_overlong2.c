#include "atoi_tests.h"

int	over_long2(void)
{
	char	*s;

	s = "-92233720368547758081";
	return (-(ft_atoi(s) != atoi(s)));
}
