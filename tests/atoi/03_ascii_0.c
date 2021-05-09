#include "atoi_tests.h"

int	ascii_0(void)
{
	return (-(ft_atoi("\0") != atoi("\0")));
}