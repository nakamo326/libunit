#include "strlen_tests.h"

int	empty_str_test(void)
{
	return (-(ft_strlen("") != strlen("")));
}
