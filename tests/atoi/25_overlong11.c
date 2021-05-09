#include "atoi_tests.h"

int	over_long11(void)
{
	char *s;

	s = "-9223372036854775809";
	return (-(ft_atoi(s) != atoi(s)));
}
