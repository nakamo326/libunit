#include "../cases.h"

int	toupper_null_char(void)
{
	if (ft_toupper('\0') == toupper('\0'))
		return (0);
	else
		return(-1);
}
