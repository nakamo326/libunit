#include "atoi_tests.h"

int	space5(void)
{
	char	*s;

	s = "\t\v\f\r\n \f-06050";
	return (-(ft_atoi(s) != atoi(s)));
}
