#include "../cases.h"

int	tolower_not_ascii(void)
{
	if (ft_tolower(555) == tolower(555))
		return (0);
	else
		return(-1);
}
