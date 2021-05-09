#include "atoi_tests.h"

int	space3(void)
{
	char	*s;

	s = "3456  ";
	return (-(ft_atoi(s) != atoi(s)));
}
