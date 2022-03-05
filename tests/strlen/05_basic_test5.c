#include "../cases.h"

int	basic_test5(void)
{
	char	*s;

	s = "B  B  K";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
