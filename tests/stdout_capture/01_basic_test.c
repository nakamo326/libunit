#include "../cases.h"
#include <stdio.h>

int	stdout_test(void)
{
	char	*str;

	capture_stdout();
	write(1, "test", 4);
	str = get_captured_stdout();
	printf("%s\n",str);
	if (!ft_strncmp(str, "test", 5))
		return (0);
	else
		return (-1);
}
