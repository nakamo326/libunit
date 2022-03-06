#include "libft.h"
#include "libunit_bonus.h"

void put_status( char *signal, char *color)
{
	ft_putstrs_fd((char *[]) {color, signal, RESET "\n", NULL}, STDOUT_FILENO);
}
