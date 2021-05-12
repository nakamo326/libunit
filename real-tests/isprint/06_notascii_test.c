#include "../cases.h"

int	isprint_not_ascii(void)
{
	return (-(!!ft_isprint(555) != !!isprint(555)));
}
