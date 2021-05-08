#include "strlen_tests.h"

int	include_nullchar_test(void)
{
	if (ft_strlen("aaaa\0bbbb") == strlen("aaaa\0bbbb"))
		return (0);
	else
		return (-1);
}
