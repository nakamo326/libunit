#include "../cases.h"

int	alnum_basic_test(void)
{
	return (-(!!ft_isalnum('a') != !!isalnum('a')));
}
