#include "strlen_tests.h"

int	double_free(void)
{
	kill(getpid(), SIGABRT);
	return (0);
}
