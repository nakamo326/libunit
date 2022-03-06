#include "../cases.h"
#include <stdio.h>

int	longtxt_test(void)
{
	char	*str;

	capture_stdout();
	printf("%0*d", INT_MAX / 2, 1);
	str = get_captured_stdout();
	printf("output: %.100s\n", str);
	if (ft_strlen(str) == INT_MAX / 2)
		return (0);
	else
		return (-1);
}
