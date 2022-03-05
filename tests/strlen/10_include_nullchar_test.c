#include "../cases.h"

int	include_nullchar_test(void)
{
	char	*s;

	s = "aaaa\0bbbb";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
