#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

#define OK			"[OK]"
#define KO			"[KO]"
#define M_SIGSEGV	"[SIGSEGV]"
#define M_SIGABRT	"[SIGABRT]"
#define M_SIGBUS	"[SIGBUS]"
#define M_SIGFPE	"[SIGFPE]"
#define M_SIGILL	"[SIGILL]"
#define M_SIGPIPE	"[SIGPIPE]"
#define M_TIMEOUT	"[TIMEOUT]"
#define M_UNKNOWN	"[UNKNOWN]"


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
		put_status(OK, GREEN);
	else if (res == -1)
		put_status(KO, RED);
	else if (res == SIGSEGV)
		put_status(M_SIGSEGV, YELLOW);
	else if (res == SIGABRT)
		put_status(M_SIGABRT, YELLOW);
	else if (res == SIGBUS)
		put_status(M_SIGBUS, YELLOW);
	else if (res == SIGFPE)
		put_status(M_SIGFPE, YELLOW);
	else if (res == SIGALRM)
		put_status(M_TIMEOUT, YELLOW);
	else if (res == SIGPIPE)
		put_status(M_SIGPIPE, YELLOW);
	else if (res == SIGILL)
		put_status(M_SIGILL, YELLOW);
	else
		put_status(M_UNKNOWN, YELLOW);
}

void	print_result_one(char *title, char *case_name, int res, size_t max_len)
{
	output_case(title, case_name, max_len);
	put_test_result(res);
}
