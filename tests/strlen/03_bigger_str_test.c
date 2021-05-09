#include "strlen_tests.h"
#include <limits.h>

int	bigger_str_test(void)
{
	int		ret;
	char	*tmp;
	size_t	i;

	i =  = UINT_MAX;;
	tmp = malloc(i + 100);
	memset(tmp, 'a', i + 100);
	tmp[i + 99] = 0;
	ret = -!(ft_strlen(tmp) != strlen(tmp));
	free(tmp);
	return (ret);
}
