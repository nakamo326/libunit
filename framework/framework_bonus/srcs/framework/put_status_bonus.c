#include "libft.h"
#include "libunit_bonus.h"
#include <unistd.h>

void	put_status( char *signal, char *color, int fd)
{
	if (isatty(fd))
		ft_putstrs_fd((char *[]){color, signal, RESET "\n", NULL}, fd);
	else
		ft_putstrs_fd((char *[]){signal, "\n", NULL}, fd);
}
