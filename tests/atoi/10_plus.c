#include "../cases.h"

int	plus(void)
{
	char	*s;

	s = "+2147483647";
	return (-(ft_atoi(s) != atoi(s)));
}
