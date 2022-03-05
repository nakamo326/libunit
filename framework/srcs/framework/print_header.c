#include "libunit.h"
#include "libft.h"

void	print_header(void)
{
	ft_putendl_fd("\n" CYAN BOLD BORDER, STDOUT_FILENO);
	ft_putendl_fd("*****    42 - Unit Tests    *****", STDOUT_FILENO);
	ft_putendl_fd(BORDER "\n" B_RESET RESET, STDOUT_FILENO);
}
