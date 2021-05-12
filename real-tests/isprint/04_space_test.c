#include "../cases.h"

int	isprint_space(void)
{
	return (-(!!ft_isprint(' ') != !!isprint(' ')));
}
