#include "../cases.h"

int	strncmp_include_nullchar_test(void)
{
	size_t	len;
	int		actual;
	int		expected;

	len = 5;
	actual = ft_strncmp("aa\0ba", "aaaaa", len);
	expected = strncmp("aa\0ba", "aaaaa", len);
	if ((actual < 0 && expected < 0) || (actual > 0 && expected > 0)
		|| (actual == 0 && expected == 0))
		return (0);
	return (-1);
}
