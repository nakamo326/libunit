#include "../cases.h"

int	over_long8(void)
{
	char	*s;

	s = "9223372036854775807a";
	return (-(ft_atoi(s) != atoi(s)));
}
