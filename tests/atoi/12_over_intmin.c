#include "atoi_tests.h"

int	over_intmin(void)
{
	char *s;

	s = -2147483649;
	return (-(ft_atoi(s) != atoi(s)));
}