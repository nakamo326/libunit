#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static int	g_pipe_fd[2];
static int	g_stdout_copy_fd;

void	capture_stdout(void)
{
	pipe(g_pipe_fd);
	g_stdout_copy_fd = dup(STDOUT_FILENO);
	dup2(g_pipe_fd[1], STDOUT_FILENO);
}

char	*get_captured_stdout(void)
{
	ssize_t	bufsize;
	ssize_t	readsize;
	ssize_t	read_status;
	char	*buf;

	dup2(g_stdout_copy_fd, STDOUT_FILENO);
	close(g_stdout_copy_fd);
	bufsize = 0;
	readsize = 0;
	while (1)
	{
		if (bufsize <= readsize)
		{
			bufsize += PIPE_BUF;
			buf = or_exit(realloc(buf, bufsize));
		}
		read_status = read(g_pipe_fd[0], buf, PIPE_BUF);
		if (read_status <= 0)
			break ;
		readsize += read_status;
	}
	buf[readsize] = '\0';
	close(g_pipe_fd[0]);
	close(g_pipe_fd[1]);
	return (buf);
}
