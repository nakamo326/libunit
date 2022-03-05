#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# define UNKNOWN SIGUSR1
# define GET     0
# define INC     1
# define SET  2
# define GREEN  "\x1b[32m"
# define RED    "\x1b[31m"
# define YELLOW "\x1b[33m"
# define CYAN   "\x1b[36m"
# define RESET  "\x1b[39m"
# define BOLD   "\x1b[1m"
# define B_RESET   "\x1b[0m"
# define BORDER "*********************************"
typedef struct s_clist	t_clist;
typedef struct s_clist	t_suite;
typedef struct s_proc
{
	pid_t	pid;
	int		res;
}	t_proc;
typedef struct s_test
{
	char	*title;
	t_suite	*suite;
}	t_test;
typedef struct s_case
{
	int		pid;
	char	*case_name;
	int		(*f_case)();
}	t_case;

bool	exists_pid(t_clist *found);
int		get_result(void);
int		launch_tests(t_clist **lst, char *title);
int		print_result_one(char *title, char *case_name, int res, size_t max_len);
size_t	get_max_len_of_case_name(t_clist *suite);
size_t	get_success_count(void);
size_t	get_testcount(void);
t_clist	*find_pid_from_finished(pid_t target, t_clist *waited);
void	err_exit(t_clist *lst, t_case *data);
void	inc_success_count(void);
void	inc_testcount(void);
void	init_test(t_clist **lst);
void	load_test(t_clist **lst, char *case_name, int (*f_case)());
void	print_cases_result(t_clist *suite, char *title);
void	print_result_all(t_clist *suite, char *title);
void	print_suite_result(void);
void	reset_success_count(void);
void	reset_testcount(void);
void	run_suite(t_clist *suite, char *title);
void	run_test(t_clist *lst);
void	set_success_count(size_t value);
void	set_testcount(size_t value);
void	wait_case(t_clist *pidlst);

#endif
