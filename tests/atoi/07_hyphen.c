#include "atoi_tests.h"

int	hyphen(void)
{
	char	*s;

	s = "-";
	return (-(ft_atoi(s) != atoi(s)));
}
