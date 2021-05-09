#include "atoi_tests.h"

int	over_long6(void)
{
	char *s;

	s = "9223372036854775807";
	return (-(ft_atoi(s) != atoi(s)));
}
