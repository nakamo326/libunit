#include "atoi_tests.h"

int	over_intmax2(void)
{
	char *s;
	s = "4294969344";
	return (-(ft_atoi(s) != atoi(s)));
}