#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

#define OK "[OK]"
#define KO "[KO]"
#define M_SIGSEGV "[SIGSEGV]"
#define M_SIGABRT "[SIGABRT]"
#define M_SIGBUS "[SIGBUS]"
#define M_SIGFPE "[SIGFPE]"
#define M_TIMEOUT "[TIMEOUT]"
#define M_UNKNOWN "[UNKNOWN]"

// [test_function]:[test_name]:[status]

void output_case(char *title, char *case_name)
{
	const int fd = STDOUT_FILENO;

	ft_putstrs_fd((char *[]){title, " : ", case_name, " : ", NULL}, fd);
}

int	print_result(char *title, char *case_name, int res)
{
	output_case(title, case_name);
	if (!res)
		ft_putendl_fd(GREEN OK RESET, STDOUT_FILENO);
	else if (res == -1)
		ft_putendl_fd(RED KO RESET, STDOUT_FILENO);
	else if (res == SIGSEGV)
		ft_putendl_fd(YELLOW M_SIGSEGV RESET, STDOUT_FILENO);
	else if (res == SIGABRT)
		ft_putendl_fd(YELLOW M_SIGABRT RESET, STDOUT_FILENO);
	else if (res == SIGBUS)
		ft_putendl_fd(YELLOW M_SIGBUS RESET, STDOUT_FILENO);
	else if (res == SIGFPE)
		ft_putendl_fd(YELLOW M_SIGFPE RESET, STDOUT_FILENO);
	else if (res == SIGALRM)
		ft_putendl_fd(YELLOW M_TIMEOUT RESET, STDOUT_FILENO);
	else
		ft_putendl_fd(YELLOW M_UNKNOWN RESET, STDOUT_FILENO);
	return (-!!res); // signal == -1 , exit = 0 , ko = -1
}

void	ft_putstrs_fd(char **strs, int fd)
{
	while (*strs)
	{
		ft_putstr_fd(*strs, fd);
		strs++;
	}
}

