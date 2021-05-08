#include "basic_tests.h"

int	null_test(void)
{
	if (ft_strlen(NULL) == 0)
		return (0);
	else
		return (-1);
}
