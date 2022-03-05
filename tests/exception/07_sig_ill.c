#include "../cases.h"

int		sig_ill(void)
{
	__asm__("jmp -10");
	return (0);
}
