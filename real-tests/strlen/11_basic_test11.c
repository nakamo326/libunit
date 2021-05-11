#include "strlen_tests.h"

int	basic_test8(void)
{
	char	*s;

	s = "B-^{```{]adsf:l];BK";
	return (-(ft_strlen(s) != strlen(s)));
}
