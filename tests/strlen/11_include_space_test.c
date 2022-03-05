#include "../cases.h"

int	include_space_test(void)
{
	char	*s;

	s = "aaa\tb\vc\fdd\r\nee ";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
