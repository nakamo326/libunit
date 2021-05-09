#include "strlen_tests.h"

int	include_allascii_test(void)
{
	char	*tmp;
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 127;
	tmp = malloc(127);
	while (i != 127)
	{
		tmp[i] = j;
		j--;
		i++;
	}
	if (ft_strlen(tmp) == strlen(tmp))
		result = 0;
	else
		result = -1;
	free(tmp);
	return(result);
}
