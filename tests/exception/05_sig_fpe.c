#include "../cases.h"

int	sig_fpe(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	j /= i;
	return (0);
}
