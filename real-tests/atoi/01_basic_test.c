#include "../cases.h"

int	atoi_basic_test(void)
{
	const char	*s = "100\n";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
