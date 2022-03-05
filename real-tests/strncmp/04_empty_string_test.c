#include "../cases.h"

int	strncmp_empty_string_test(void)
{
	if (ft_strncmp("", "", 1) == strncmp("", "", 1))
		return (0);
	else
		return(-1);
}
