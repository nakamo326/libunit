#include "libft.h"

int	ft_is_prime(int nb)
{
	int	x;

	if (nb <= 1)
		return (0);
	x = 2;
	while (x < nb)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}
