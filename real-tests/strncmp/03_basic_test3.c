#include "../cases.h"

int	strncmp_basic_test3(void)
{
	if (ft_strncmp("aaaaaaaaaa", "aaaaaaaaab", 9)
		== strncmp("aaaaaaaaaa", "aaaaaaaaab", 9))
		return (0);
	else
		return(-1);
}
