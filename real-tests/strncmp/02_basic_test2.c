#include "../cases.h"

int	strncmp_basic_test2(void)
{

	if (ft_strncmp("aaaaaaaaaa", "aaaaaaaaab", 10)
		== strncmp("aaaaaaaaaa", "aaaaaaaaab", 10))
		return (0);
	else
		return(-1);
}
