#include "../cases.h"

int	alnum_basic_test5(void)
{
	return (-(!!ft_isalnum(48 + (1 << 20)) != !!isalnum(48 + (1 << 20))));
}
