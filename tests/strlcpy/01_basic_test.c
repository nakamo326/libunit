#include "../cases.h"

int	strlcpy_basic_test(void)
{
	char	str[10];

	if (ft_strlcpy(str, "aiueo", 6) == 5 && strcmp(str, "aiueo") == 0)
		return (0);
	else
		return (-1);
}
