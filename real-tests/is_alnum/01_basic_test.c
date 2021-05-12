#include "../cases.h"

int	alnum_basic_test(void)
{
	// printf("%d %d\n", ft_isalnum('a'), isalnum('a'));
	return (-(!!ft_isalnum('a') != !!isalnum('a')));
}
