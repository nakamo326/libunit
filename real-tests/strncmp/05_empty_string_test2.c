#include "../cases.h"

int	strncmp_empty_string_test2(void)
{
	int libret;
	int ftret;

	libret = strncmp("aaaaa", "", 5);
	ftret = ft_strncmp("aaaaa", "", 5);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return(-1);
}
