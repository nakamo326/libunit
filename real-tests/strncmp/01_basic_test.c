#include "../cases.h"

int	strncmp_basic_test(void)
{
	int	libret;
	int	ftret;

	libret = strncmp("aa", "aa", 10);
	ftret = ft_strncmp("aa", "aa", 10);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return (-1);
}
