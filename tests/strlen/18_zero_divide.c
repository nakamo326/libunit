#include "strlen_tests.h"

int	zero_divide(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	j /= i;
	return (-1);
}
