#include "../cases.h"

int	over_long12(void)
{
	char	*s;

	s = "9223372036854775808";
	return (-(ft_atoi(s) != atoi(s)));
}
