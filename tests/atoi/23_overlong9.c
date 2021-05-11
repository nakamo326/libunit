#include "../cases.h"

int	over_long9(void)
{
	char	*s;

	s = "9223372036854775806a";
	return (-(ft_atoi(s) != atoi(s)));
}
