#include "strlen_tests.h"

int	bigger_str_test(void)
{
	char	*tmp;
	size_t	len;

	len = 1000;
	memset(tmp, 'a', len);
	tmp[len] = '\0';
	if (ft_strlen(tmp) == strlen(tmp))
		return (0);
	else
		return (-1);
}
