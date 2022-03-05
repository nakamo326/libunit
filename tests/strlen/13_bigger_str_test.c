#include "../cases.h"
#include <limits.h>

int	bigger_str_test(void)
{
	int		ret;
	char	*tmp;
	size_t	i;

	i = UINT_MAX;
	tmp = malloc(i + 100);
	memset(tmp, 'a', i + 100);
	tmp[i + 99] = 0;
	if (ft_strlen(tmp) == strlen(tmp))
		ret = 0;
	else
		ret = -1;
	free(tmp);
	return (ret);
}
