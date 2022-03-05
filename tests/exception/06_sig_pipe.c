#include "../cases.h"

int		sig_pipe(void)
{
	int		pipe_fd[2];

	pipe(pipe_fd);
	close(pipe_fd[0]);
	write(pipe_fd[1], "42", 3);
	close(pipe_fd[1]);
	return (0);
}
