#include "atoi_tests.h"

int	space2(void)
{
	char	*s;

	s = "  12345  6789";
	return (-(ft_atoi(s) != atoi(s)));
}
