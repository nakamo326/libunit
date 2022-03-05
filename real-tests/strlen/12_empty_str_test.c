#include "../cases.h"

int	empty_str_test(void)
{
	const char	*s = "";

	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
