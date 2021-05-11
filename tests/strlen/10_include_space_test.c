#include "../cases.h"

int	include_space_test(void)
{
	return (-(ft_strlen("aaa\tb\vc\fdd\r\nee ") != strlen("aaa\tb\vc\fdd\r\nee ")));
}
