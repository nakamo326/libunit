#include "../cases.h"

int	space2(void)
{
	const char *s = "  12345  6789";
	
	if (ft_atoi(s) == atoi(s))
		return (0);
	else
		return (-1);
}
