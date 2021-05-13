#include "../cases.h"

int	strncmp_basic_test(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 10;
	act = ft_strncmp("aa", "aa", len);
	expected = strncmp("aa", "aa", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
