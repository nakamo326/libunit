#include "../cases.h"

int	is_prime_intmax_test(void)
{
	if (ft_is_prime(INT_MAX) == 1)
		return (0);
	else
		return (-1);
}
