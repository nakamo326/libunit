#include "../cases.h"

int	strncmp_zerolen_test(void)
{
	if (ft_strncmp("bbbbb", "aaaaa", 0) == strncmp("bbbbb", "aaaaa", 0))
		return (0);
	else
		return(-1);
}
