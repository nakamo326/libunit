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

int f_ret()
{
	char *s = "aiueo";
	(void)s;
	// s[0] = 1;
	return (0);
}

int fork_test(int (*func)())
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
	if (WIFEXITED(status))	//return 0 or -1
		return ((char)WEXITSTATUS(status));
	if (WIFSIGNALED(status)) //異常終了 segv buse abort etc...
		return (WTERMSIG(status));
	return (0);
}

void res(int ret)
{
	if (!ret)
		printf("OK\n");
	else if (ret == SIGSEGV)
		printf("SEGV\n");
	else if (ret == SIGBUS)
		printf("BUS\n");
}

int main()
{
	res(fork_test(f_ret));
	res(fork_test(f_signal));
}
