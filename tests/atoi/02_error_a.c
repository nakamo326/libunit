#include "atoi_tests.h"

int	error_a(void)
{
	return (-(ft_atoi("a") != atoi("a")));
}