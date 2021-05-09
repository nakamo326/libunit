#include "atoi_tests.h"

int	over_long13(void)
{
	char	*s;

	s = "63410682753376583680";
	return (-(ft_atoi(s) != atoi(s)));
}
