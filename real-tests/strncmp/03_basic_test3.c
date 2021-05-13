#include "../cases.h"

int	strncmp_basic_test3(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 9;
	act = ft_strncmp("aaaaaaaaaa", "aaaaaaaaab", len);
	expected = strncmp("aaaaaaaaaa", "aaaaaaaaab", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
