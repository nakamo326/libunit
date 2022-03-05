#include "../cases.h"

int	null_p(void)
{
	char	*s;

	s = NULL;
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
