#include "../cases.h"

int	toupper_not_ascii(void)
{
	if (ft_toupper(555) == toupper(555))
		return (0);
	else
		return (-1);
}
