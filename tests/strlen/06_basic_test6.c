#include "../cases.h"

int	basic_test6(void)
{
	char	*s;

	s = "BB~~+>?K";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
