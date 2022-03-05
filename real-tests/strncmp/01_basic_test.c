#include "../cases.h"

int	strncmp_basic_test(void)
{
	if (ft_strncmp("aa", "aa", 10) == strncmp("aa", "aa", 10))
		return (0);
	else
		return(-1);
}
