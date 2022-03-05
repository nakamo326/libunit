#include "../cases.h"

int	strncmp_empty_string_test3(void)
{
	if (ft_strncmp("", "aaaaa", 5) == strncmp("", "aaaaa", 5))
		return (0);
	else
		return(-1);
}
