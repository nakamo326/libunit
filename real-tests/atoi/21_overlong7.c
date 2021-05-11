#include "atoi_tests.h"

int	over_long7(void)
{
	char	*s;

	s = "92233720368547758071";
	return (-(ft_atoi(s) != atoi(s)));
}
