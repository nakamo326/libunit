#include "../cases.h"

int	basic_test3(void)
{
	const char	*s = "aaabcdee";

	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
