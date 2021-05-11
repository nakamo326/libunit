#include "../cases.h"

int	over_intmax(void)
{
	char	*s;

	s = "6442450944";
	return (-(ft_atoi(s) != atoi(s)));
}
