#include "../cases.h"

int	strncmp_empty_string_test3(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 5;
	act = ft_strncmp("", "aaaaa", len);
	expected = strncmp("", "aaaaa", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
