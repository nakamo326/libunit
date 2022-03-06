#include "../cases.h"

int	strncmp_zerolen_test(void)
{
	int	libret;
	int	ftret;

	libret = strncmp("bbbbb", "aaaaa", 0);
	ftret = ft_strncmp("bbbbb", "aaaaa", 0);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return (-1);
}
