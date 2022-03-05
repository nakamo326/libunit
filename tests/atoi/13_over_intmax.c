#include "../cases.h"

int	over_intmax(void)
{
	char	*s;

	s = "6442450944";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
