#include "../cases.h"

int	over_long10(void)
{
	const char	*s = "922337203685477580a";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
