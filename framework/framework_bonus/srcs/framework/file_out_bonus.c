#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static void	print_log(int fd, t_clist *suite, char *title, size_t max_len)
{
	t_proc	*proc;
	t_case	*testcase;

	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		testcase = suite->data;
		proc = &testcase->proc;
		if (proc->res)
		{
			output_case(title, testcase->case_name, max_len, fd);
			put_test_result(proc->res, fd);
		}
		suite = suite->next;
	}
}

static int	open_file(char *title)
{
	int				fd;
	char			*filename;
	const mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	filename = or_exit(ft_strjoin(title, ".log"));
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, mode);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	free(filename);
	return (fd);
}

void	create_log_file(t_clist *suite, char *title, size_t max_len)
{
	int	fd;

	fd = open_file(title);
	print_log(fd, suite, title, max_len);
	close(fd);
}
