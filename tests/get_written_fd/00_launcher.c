#include "../cases.h"

int	get_written_fd_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", get_written_fd_basic_test);
	return (launch_tests(&lst, "GET_WRITTEN_FD"));
}
