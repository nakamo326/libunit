#include "../cases.h"

int	strncmp_include_nullchar_test(void)
{
	int	libret;
	int	ftret;

	libret = strncmp("aa\0ba", "aaaaa", 5);
	ftret = ft_strncmp("aa\0ba", "aaaaa", 5);
	if ((libret != 0 && ftret != 0)
		|| (libret == 0 && ftret == 0))
		return (0);
	else
		return (-1);
}
