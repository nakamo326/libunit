#include "../cases.h"

int	exception_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "ko_case", ko_case);
	load_test(&lst, "bus_error", bus_error);
	load_test(&lst, "time_out", time_out);
	load_test(&lst, "sig_abrt", sig_abrt);
	load_test(&lst, "sig_fpe", sig_fpe);
	load_test(&lst, "sig_pipe", sig_pipe);
	load_test(&lst, "sig_ill", sig_ill);
	return (launch_tests(&lst, "EXCEPTION"));
}
