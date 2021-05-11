#include "../cases.h"

int	toupper_null_char(void)
{
	return (-(ft_toupper('\0') != toupper('\0')));
}
