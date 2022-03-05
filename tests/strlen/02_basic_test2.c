#include "../cases.h"

int	basic_test2(void)
{
	char	*s;

	s = "BBK";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
