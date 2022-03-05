#include "../cases.h"

int	basic_test(void)
{
	const char	*s = "Hello";

	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
