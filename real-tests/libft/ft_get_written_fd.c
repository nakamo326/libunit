#include "libft.h"

int	ft_get_written_fd(char *str)
{
	int		pipe_fd[2];

	pipe(pipe_fd);
	close(pipe_fd[0]);
	write(pipe_fd[1], str, ft_strlen(str));
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
