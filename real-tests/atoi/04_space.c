#include "../cases.h"

int	space(void)
{
	const char	*s = "  ";

	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
