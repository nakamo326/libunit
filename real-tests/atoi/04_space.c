#include "../cases.h"

int	space(void)
{
	char	*s;

	s = "  ";
	return (-(ft_atoi(s) != atoi(s)));
}
