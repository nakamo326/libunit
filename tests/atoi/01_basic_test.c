#include "atoi_tests.h"

int	basic_test(void)
{
	return (-(ft_atoi("100\n") != atoi("100\n")));
}