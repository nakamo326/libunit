#include "../cases.h"

int		sig_ill(void)
{
	__asm__("jmp -3000");
	return (0);
}
