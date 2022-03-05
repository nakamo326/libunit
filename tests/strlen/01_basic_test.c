#include "../cases.h"

int	basic_test(void)
{
	char	*s;

	s = "Hello";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
