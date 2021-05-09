#include "strlen_tests.h"

int	bus_error(void)
{
	char	*s;

	s = "";
	s[0] = 1;
	return (0);
}
