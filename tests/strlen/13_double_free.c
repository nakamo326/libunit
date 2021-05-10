#include "strlen_tests.h"

int	double_free(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (-1);
	free(s);
	free(s);
	return (0);
}
