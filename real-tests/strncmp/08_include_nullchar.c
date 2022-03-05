#include "../cases.h"

int	strncmp_include_nullchar_test(void)
{
	if (ft_strncmp("aa\0ba", "aaaaa", 5)
		== strncmp("aa\0ba", "aaaaa", 5))
		return (0);
	else
		return(-1);
}
