#include "../cases.h"

int	alnum_basic_test4(void)
{
	return (-(ft_isalnum(300) != isalnum(300)));
}
