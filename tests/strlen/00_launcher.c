#include "libunit.h"
#include "strlen_tests.h"

int	strlen_launcher(void)
{
	t_clist *lst;

	puts("\x1b[1mSTRLEN\x1b[0m\n");
	load_test(&lst, "basic_test", basic_test);
	// load_test(&lst, "", );
	// load_test(&lst, "", );
	// load_test(&lst, "", );
	// load_test(&lst, "", );
	// load_test(&lst, "", );
	// load_test(&lst, "", );
	return (launch_tests(&lst));
}