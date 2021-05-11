#include "strlen_tests.h"

int	include_nullchar_test(void)
{
	return (-(ft_strlen("aaaa\0bbbb") != strlen("aaaa\0bbbb")));
}
