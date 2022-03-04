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

typedef struct s_clist	t_clist;
typedef struct s_data
{
	char	*case_name;
	int		(*f_case)();
}	t_data;

int		ft_setptr(void *dest, void *p);
void	err_exit(t_clist *lst, t_data *data);
void	load_test(t_clist **lst, char *case_name, int (*f_case)());
int		launch_tests(t_clist **lst, char *title);
int		print_result(char *case_name, int res);
int		case_result(t_clist *lst);
int		run_test(t_clist *lst, char *title);
size_t	my_strlen(char *s);
int		norm_hacker(int flag, int assign);

#endif
