#include "../cases.h"

int	strlcpy_literal_test(void)
{
	char	*str;

	str = "";
	if (ft_strlcpy(str, "aiueo", 6) == 6 && strcmp(str, "aiueo"))
		return (0);
	else
		return (-1);
}
