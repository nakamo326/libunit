#include "../cases.h"
#include <stdio.h>

int	stdout_test(void)
{
	char	*str;

	capture_stdout();
	// write(1, "test", 4);
	printf("%0*d", INT_MAX / 2, 1);
	exit(0);
	str = get_captured_stdout();
	printf("output: %.100s\n", str);
	// if (!ft_strncmp(str, "test", 5))
	if (ft_strlen(str) == INT_MAX / 2)
		return (0);
	else
		return (-1);
}
