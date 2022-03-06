#include "../cases.h"

int	empty_launcher(void)
{
	t_clist	*lst;

	return (launch_tests(&lst, "EMPTY"));
}
