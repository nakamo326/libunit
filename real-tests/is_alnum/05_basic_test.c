#include "../cases.h"

int	alnum_basic_test5(void)
{
	// printf("%d\n",  isalnum(48 + (1 << 20)));
	// printf("%d\n %d\n", ft_isalnum(48 + (1 << 20)), isalnum(48 + (1 << 20)));
	return (-(ft_isalnum(48 + (1 << 20)) != isalnum(48 + (1 << 20))));
}
