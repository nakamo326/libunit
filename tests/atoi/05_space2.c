#include "../cases.h"

int	space2(void)
{
	char	*s;

	s = "  12345  6789";
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
