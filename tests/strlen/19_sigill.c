#include "../cases.h"

int	sig_ill(void)
{
	kill(getpid(), SIGILL);
	return (0);
}
