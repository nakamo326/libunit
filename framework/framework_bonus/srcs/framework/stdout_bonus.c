#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

static char			*g_buf;
static int			g_stdout_copy_fd;
static pthread_t	g_th;
static int			g_capture_pipe[2];

void	*drain_stdout(void *p)
{
	(void)p;
	g_buf = get_string_from_fd(g_capture_pipe[0], PIPE_BUF);
	close(g_capture_pipe[0]);
	return (NULL);
}

void	capture_stdout(void)
{
	pipe(g_capture_pipe);
	g_stdout_copy_fd = dup(STDOUT_FILENO);
	dup2(g_capture_pipe[1], STDOUT_FILENO);
	close(g_capture_pipe[1]);
	pthread_create(&g_th, NULL, drain_stdout, NULL);
}

void	restore_stdout(void)
{
	dup2(g_stdout_copy_fd, STDOUT_FILENO);
	close(g_stdout_copy_fd);
}

char	*get_captured_stdout(void)
{
	fflush(stdout);
	restore_stdout();
	pthread_join(g_th, NULL);
	return (g_buf);
}
