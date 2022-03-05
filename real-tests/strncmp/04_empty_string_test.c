#include "../cases.h"

int	strncmp_empty_string_test(void)
{
	int libret;
	int ftret;

	libret = strncmp("", "", 1);
	ftret = ft_strncmp("", "", 1);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return(-1);
}
