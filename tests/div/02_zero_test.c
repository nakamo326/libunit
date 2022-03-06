#include "../cases.h"
#include <math.h>

int	div_zero_test(void)
{
	if (isinf(ft_div(10, 0)))
		return (0);
	else
		return (-1);
}
