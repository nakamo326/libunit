#include "../cases.h"

int	strncmp_zerolen_test(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 0;
	act = ft_strncmp("bbbbb", "aaaaa", len);
	expected = strncmp("bbbbb", "aaaaa", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
