#include "../cases.h"

int	strncmp_basic_test2(void)
{
	int	libret;
	int	ftret;

	libret = strncmp("aaaaaaaaaa", "aaaaaaaaab", 10);
	ftret = ft_strncmp("aaaaaaaaaa", "aaaaaaaaab", 10);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return (-1);
}
