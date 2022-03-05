#include "../cases.h"

int	over_long(void)
{
	const char	*s = "-9223372036854775808";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
