#include "../cases.h"

int	over_long3(void)
{
	char	*s;

	s = "-9223372036854775808a";
	return (-(ft_atoi(s) != atoi(s)));
}
