#include "../cases.h"

int	include_space_test(void)
{
	const char	*s = "aaa\tb\vc\fdd\r\nee ";

	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
