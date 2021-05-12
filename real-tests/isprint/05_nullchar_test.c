#include "../cases.h"

int	isprint_null_char(void)
{
	return (-(!!ft_isprint('\0') != !!isprint('\0')));
}
