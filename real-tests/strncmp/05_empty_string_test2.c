#include "../cases.h"

int	strncmp_empty_string_test2(void)
{
	if (ft_strncmp("aaaaa", "", 5) == strncmp("aaaaa", "", 5))
		return (0);
	else
		return(-1);
}
