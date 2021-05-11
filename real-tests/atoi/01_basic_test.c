#include "../cases.h"

int	atoi_basic_test(void)
{
	return (-(ft_atoi("100\n") != atoi("100\n")));
}
