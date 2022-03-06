#include "../cases.h"

int	tolower_null_char(void)
{
	if (ft_tolower('\0') == tolower('\0'))
		return (0);
	else
		return (-1);
}
