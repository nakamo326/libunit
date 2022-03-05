#include "../cases.h"

int	over_long9(void)
{
	char	*s;

	s = "9223372036854775806a";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
