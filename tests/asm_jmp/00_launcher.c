#include "../cases.h"

int	asm_jmp_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", asm_jmp_basic_test);
	return (launch_tests(&lst, "ASM_JMP"));
}
