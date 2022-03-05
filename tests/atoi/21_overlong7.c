#include "../cases.h"

int	over_long7(void)
{
	char	*s;

	s = "92233720368547758071";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
