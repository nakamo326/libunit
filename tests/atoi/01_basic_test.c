#include "../cases.h"

int	atoi_basic_test(void)
{
	char	*s;

	s = "100\n";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
