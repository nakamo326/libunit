#include "atoi_tests.h"

int	space4(void)
{
	char	*s;

	s = "\t\v\f\r\n \f- \f\t\n\r    06050";
	return (-(ft_atoi(s) != atoi(s)));
}