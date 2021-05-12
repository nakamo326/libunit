#include "../cases.h"

int	alnum_basic_test3(void)
{
	return (-(!!ft_isalnum(0) != !!isalnum(0)));
}
