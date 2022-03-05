#include "../cases.h"

int	over_long3(void)
{
	const char	*s = "-9223372036854775808a";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
