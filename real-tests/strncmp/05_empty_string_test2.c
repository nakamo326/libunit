#include "../cases.h"

int	strncmp_empty_string_test2(void)
{
	size_t	len;
	int		actual;
	int		expected;

	len = 5;
	actual = ft_strncmp("aaaaa", "", len);
	expected = strncmp("aaaaa", "", len);
	if ((actual < 0 && expected < 0) || (actual > 0 && expected > 0)
		|| (actual == 0 && expected == 0))
		return (0);
	return (-1);
}
