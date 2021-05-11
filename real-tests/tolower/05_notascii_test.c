#include "../cases.h"

int	tolower_not_ascii(void)
{
	return (-(ft_tolower(555) != tolower(555)));
}
