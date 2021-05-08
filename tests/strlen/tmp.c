#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

int f_signal()
{
	char *s = "aiueo";
	(void)s;
	s[0] = 1;
	return (0);
}

int f(int (*func)())
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit(0);
	else if (pid == 0)
		exit(func());
	wait(&status);
	//int status変数
	//00    00    00     00
	//            ↑      ↑
	//          返り値  SIGNAL
	if (WIFEXITED(status))
		return ((char)WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0);
}

int main()
{
	int ret = f(f_signal);

	if (!ret)
		printf("OK\n");
	else if (ret == SIGSEGV)
		printf("SEGV\n");
	else if (ret == SIGBUS)
		printf("BUS\n");
}
