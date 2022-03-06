#include "../cases.h"
#include <stdio.h>

int	mediumtxt_test(void)
{
	char	*str;

	capture_stdout();
	printf("%0*d", 500000, 1);
	str = get_captured_stdout();
	printf("output: %.100s\n", str);
	if (ft_strlen(str) == 500000)
		return (0);
	else
		return (-1);
}
