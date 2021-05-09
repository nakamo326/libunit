#include "../../framework/libunit.h"

int	isascii_launcher(void)
{
	t_clist *lst;

	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	load_test(&lst, "", );
	return (launch_tests(&lst));
}
