#include "../cases.h"

int	over_long8(void)
{
	char	*s;

	s = "9223372036854775807a";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
