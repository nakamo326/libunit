#include "../cases.h"

int	strncmp_zerolen_test(void)
{
	size_t	len;
	int		actual;
	int		expected;

	len = 0;
	actual = ft_strncmp("bbbbb", "aaaaa", len);
	expected = strncmp("bbbbb", "aaaaa", len);
	if ((actual < 0 && expected < 0) || (actual > 0 && expected > 0)
		|| (actual == 0 && expected == 0))
		return (0);
	return (-1);
}
