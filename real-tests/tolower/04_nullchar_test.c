#include "../cases.h"

int	tolower_null_char(void)
{
	return (-(ft_tolower('\0') != tolower('\0')));
}
