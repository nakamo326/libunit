#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

static int	g_capture_pipe[2];
// static int	g_output_pipe[2];
static char	*g_buf;
static int	g_stdout_copy_fd;

int	or_exit_i(int res)
{
	if (res == -1)
	{
		perror("error");
		exit(-1);
	}
	return (res);
}

// char	*store_stdout_to_buffer(void)
// {
// 	char	*buf;

// 	close(STDOUT_FILENO);
// 	buf = get_string_from_fd(g_capture_pipe[0], PIPE_BUF);
// 	return (buf);
// }

// void	transport_buf_to_parent(char *buf)
// {
// 	// fprintf(stderr, "%s\n", __func__);
// 	ft_putstr_fd(buf, g_output_pipe[1]);
// 	close(g_output_pipe[1]);
// }

void	tmp(void)
{
	g_buf = store_stdout_to_buffer();
	// transport_buf_to_parent(g_buf);
	// fprintf(stderr, "%s\n", __func__);
	// free(g_buf);
}

void	drain_stdout()
{
	pid_t	pid;
	char	*buf;
	pthread_t th;

	close(g_capture_pipe[1]);
	pthread_create(&th, NULL, tmp, NULL);
	pthread_join(th, NULL);
	// pid = fork();
	// if (pid == -1)
	// {
	// 	perror("fork");
	// 	exit(-1);
	// }
	// if (!pid)
	// {
		// buf = store_stdout_to_buffer();
		// transport_buf_to_parent(buf);
		// fprintf(stderr, "%s\n", __func__);
		// free(buf);
	// 	exit(EXIT_SUCCESS);
	// }
	close(g_capture_pipe[0]);
	// close(g_output_pipe[1]);
}

void	capture_stdout(void)
{
	or_exit_i(pipe(g_capture_pipe));
	g_stdout_copy_fd = dup(STDOUT_FILENO);
	or_exit_i(dup2(g_capture_pipe[1], STDOUT_FILENO));
	drain_stdout();
}

void	restore_stdout()
{
	or_exit_i(dup2(g_stdout_copy_fd, STDOUT_FILENO));
	close(g_stdout_copy_fd);
}

char	*get_captured_stdout(void)
{
	// char	*buf;

	fflush(stdout);
	restore_stdout();
	// buf = get_string_from_fd(g_output_pipe[0], PIPE_BUF);
	// wait(NULL);
	return (g_buf);
}
