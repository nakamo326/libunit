#include "../cases.h"

int	strncmp_empty_string_test(void)
{
	size_t	len;
	int		actual;
	int		expected;

	len = 1;
	actual = ft_strncmp("", "", len);
	expected = strncmp("", "", len);
	if ((actual < 0 && expected < 0) || (actual > 0 && expected > 0)
		|| (actual == 0 && expected == 0))
		return (0);
	return (-1);
}
