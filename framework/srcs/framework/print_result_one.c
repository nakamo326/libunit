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

#define PADDING_MAX 100

// [test_function]:[test_name]:[status]

static void	put_padding_fd(size_t size, int fd)
{
	size_t	i;
	char	spaces[PADDING_MAX];

	if (size > PADDING_MAX)
		return ;
	i = 0;
	while (i < size)
	{
		spaces[i] = ' ';
		i++;
	}
	write(fd, spaces, size);
}

static void	put_case_name_fd(char *case_name, size_t max_len, int fd)
{
	const size_t	padding_size = max_len - ft_strlen(case_name);
	const size_t	front_padding_size = padding_size / 2;
	const size_t	back_padding_size = padding_size - front_padding_size;

	put_padding_fd(front_padding_size, fd);
	ft_putstr_fd(case_name, fd);
	put_padding_fd(back_padding_size, fd);
}

static void	output_case(char *title, char *case_name, size_t max_len)
{
	const int	fd = STDOUT_FILENO;

	ft_putstrs_fd((char *[]){title, " : ", NULL}, fd);
	put_case_name_fd(case_name, max_len, fd);
	ft_putstr_fd(": ", fd);
}

static void	put_test_result(int res)
{
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
}

void	print_result_one(char *title, char *case_name, int res, size_t max_len)
{
	output_case(title, case_name, max_len);
	put_test_result(res);
}
