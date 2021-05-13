#include "../cases.h"

int	isprint_stdspace(void)
{
	return (-(!!ft_isprint('\t') != !!isprint('\t')));
}
