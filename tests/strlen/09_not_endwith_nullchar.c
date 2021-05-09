#include "strlen_tests.h"

int	not_endwith_nullchar(void)
{
	char	tmp[10];

	memset(tmp, 'a', sizeof(tmp));
	return(-(ft_strlen(tmp) != strlen(tmp)));
}
