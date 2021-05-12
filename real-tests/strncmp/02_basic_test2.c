#include "../cases.h"

int	strncmp_basic_test2(void)
{
	size_t	len;
	int		actual;
	int		expected;

	len = 10;
	actual = ft_strncmp("aaaaaaaaaa", "aaaaaaaaab", len);
	expected = strncmp("aaaaaaaaaa", "aaaaaaaaab", len);
	if ((actual < 0 && expected < 0) || (actual > 0 && expected > 0)
		|| (actual == 0 && expected == 0))
		return (0);
	return (-1);
}
