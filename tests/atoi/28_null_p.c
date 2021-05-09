#include "atoi_tests.h"

int	null_p(void)
{
	char *s;

	s = NULL;
	return (-(ft_atoi(s) != atoi(s)));
}
