#include "../cases.h"

int	basic_test4(void)
{
	char	*s;

	s = "BBK09138";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
