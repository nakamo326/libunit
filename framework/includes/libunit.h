#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
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
typedef struct s_test
{
	char	*title;
	t_suite	*suite;
}	t_test;
typedef struct s_data
{
	int		pid;
	char	*case_name;
	int		(*f_case)();
}	t_data;

int		case_result(t_clist *lst);
int		ft_setptr(void *dest, void *p);
int		launch_tests(t_clist **lst, char *title);
int		norm_hacker(int flag, int assign);
int		print_result(char *title, char *case_name, int res, size_t max_len);
int		run_test(t_clist *suite, char *title);
size_t	get_max_len_of_case_name(t_clist *suite);
size_t	get_testcount();
void	err_exit(t_clist *lst, t_data *data);
void	ft_putstrs_fd(char **strs, int fd);
void	inc_testcount();
void	load_test(t_clist **lst, char *case_name, int (*f_case)());
void	print_suite_result(int success_num, int total_num);
void	reset_testcount();
void	set_testcount(size_t value);

#endif
