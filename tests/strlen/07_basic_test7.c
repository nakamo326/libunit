#include "../cases.h"

int	basic_test7(void)
{
	char	*s;

	s = "Basdfqq?????[@@BK";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
