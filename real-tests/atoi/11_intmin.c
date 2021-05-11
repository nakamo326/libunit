#include "atoi_tests.h"

int	intmin(void)
{
	char	*s;

	s = "-2147483648";
	return (-(ft_atoi(s) != atoi(s)));
}
