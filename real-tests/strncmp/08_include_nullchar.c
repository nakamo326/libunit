#include "../cases.h"

int	strncmp_include_nullchar_test(void)
{
	size_t	len;
	int		act;
	int		expected;
	size_t	bitlen;

	bitlen = sizeof(int) * CHAR_BIT - 1;
	len = 5;
	act = ft_strncmp("aa\0ba", "aaaaa", len);
	expected = strncmp("aa\0ba", "aaaaa", len);
	return (-((act ^ expected) >> bitlen || (--act ^ --expected) >> bitlen));
}
