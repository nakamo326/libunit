#include "strlen_tests.h"

int	bus_error(void)
{
	((char *)"aiuaeo")[0] = 1;
	return (0);
}
