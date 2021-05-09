#include "strlen_tests.h"

int	bigger_str_test(void)
{
	char	tmp[1000];

	memset(tmp, 'a', 1000);
	tmp[1000] = '\0';
	return (-!(ft_strlen(tmp) != strlen(tmp)));
}
