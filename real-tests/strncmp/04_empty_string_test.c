#include "../cases.h"

int	strncmp_empty_string_test(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 1;
	act = ft_strncmp("", "", len);
	expected = strncmp("", "", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
