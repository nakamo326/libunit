#include "../cases.h"

int	over_intmax2(void)
{
	char	*s;

	s = "4294969344";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
